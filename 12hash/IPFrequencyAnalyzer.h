#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <regex>
#include <random>

namespace IPAnalysis {

/**
 * @brief 超大日志文件IP频次分析器
 * 
 * 解决问题：给定一个超过100GB的日志文件，包含大量IP地址，找到出现次数最多的IP地址
 * 
 * 核心思想：哈希切分 + 分别统计 + 全局合并
 * 1. 哈希分割：将大日志文件按IP地址哈希值分割成多个小文件
 *    - 保证相同的IP地址一定会分配到同一个小文件中
 * 2. 分别统计：对每个小文件使用map统计IP出现次数，找到局部最高频次IP
 * 3. 全局合并：比较所有小文件的局部最高频次IP，找到全局最高频次IP
 */
class IPFrequencyAnalyzer {
private:
    static constexpr size_t MEMORY_LIMIT = 1024 * 1024 * 1024; // 1GB内存限制
    static constexpr size_t BUFFER_SIZE = 64 * 1024 * 1024;    // 64MB 缓冲区
    static constexpr size_t PARTITION_COUNT = 1000;             // 分割成1000个小文件
    static constexpr size_t MAX_IP_LENGTH = 15;                 // IPv4最大长度 xxx.xxx.xxx.xxx
    
    /**
     * @brief IP地址哈希函数
     * 使用简单但有效的字符串哈希算法，确保相同IP分配到相同文件
     */
    static size_t hash_ip(const std::string& ip) {
        size_t hash = 5381;
        for (char c : ip) {
            hash = ((hash << 5) + hash) + static_cast<unsigned char>(c);
        }
        return hash % PARTITION_COUNT;
    }
    
    /**
     * @brief 验证IP地址格式是否正确
     * 简单的IPv4格式验证：xxx.xxx.xxx.xxx
     */
    static bool isValidIP(const std::string& ip) {
        if (ip.empty() || ip.length() > MAX_IP_LENGTH) {
            return false;
        }
        
        // 简单的正则表达式验证IPv4格式
        std::regex ip_pattern(R"(^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$)");
        std::smatch match;
        
        if (!std::regex_match(ip, match, ip_pattern)) {
            return false;
        }
        
        // 验证每个数字段是否在0-255范围内
        for (int i = 1; i <= 4; ++i) {
            int num = std::stoi(match[i].str());
            if (num < 0 || num > 255) {
                return false;
            }
        }
        
        return true;
    }
    
    /**
     * @brief 从日志行中提取IP地址
     * 支持多种常见的日志格式
     */
    static std::string extractIP(const std::string& log_line) {
        // 常见的IP地址正则表达式
        std::regex ip_pattern(R"((\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}))");
        std::smatch match;
        
        if (std::regex_search(log_line, match, ip_pattern)) {
            std::string ip = match[1].str();
            if (isValidIP(ip)) {
                return ip;
            }
        }
        
        return ""; // 未找到有效IP
    }
    
public:
    /**
     * @brief 将大日志文件按IP地址哈希值分割成多个小文件
     * 
     * 关键特性：相同的IP地址会被分配到相同编号的小文件中
     * 这是算法正确性的核心保证
     * 
     * @param input_file 输入日志文件路径
     * @param output_prefix 输出文件前缀（如"log_part"会生成log_part_0.txt等）
     * @return 是否成功
     */
    static bool partitionLogFile(const std::string& input_file, const std::string& output_prefix) {
        std::cout << "开始分割日志文件: " << input_file << std::endl;
        
        // 第一阶段：读取所有数据并按哈希值分组到内存中
        std::ifstream infile(input_file);
        if (!infile.is_open()) {
            std::cerr << "错误：无法打开输入文件 " << input_file << std::endl;
            return false;
        }
        
        // 使用vector数组存储每个分区的IP地址
        std::vector<std::vector<std::string>> partitions(PARTITION_COUNT);
        
        std::string line;
        size_t processed_count = 0;
        size_t valid_ip_count = 0;
        size_t invalid_lines = 0;
        
        std::cout << "第一阶段：读取日志并提取IP地址..." << std::endl;
        
        // 逐行读取日志并提取IP地址
        while (std::getline(infile, line)) {
            processed_count++;
            
            // 从日志行中提取IP地址
            std::string ip = extractIP(line);
            
            if (!ip.empty()) {
                size_t hash_value = hash_ip(ip);
                partitions[hash_value].push_back(ip);
                valid_ip_count++;
            } else {
                invalid_lines++;
            }
            
            // 进度显示
            if (processed_count % 100000 == 0) {
                std::cout << "已处理 " << processed_count << " 行，提取到 " << valid_ip_count << " 个有效IP" << std::endl;
            }
        }
        infile.close();
        
        std::cout << "第二阶段：写入分割文件..." << std::endl;
        
        // 第二阶段：将每个分区的IP地址写入对应文件
        size_t non_empty_partitions = 0;
        for (size_t i = 0; i < PARTITION_COUNT; ++i) {
            if (!partitions[i].empty()) {
                non_empty_partitions++;
                std::string filename = output_prefix + "_" + std::to_string(i) + ".txt";
                std::ofstream outfile(filename);
                if (!outfile.is_open()) {
                    std::cerr << "错误：无法创建输出文件 " << filename << std::endl;
                    return false;
                }
                
                for (const auto& ip : partitions[i]) {
                    outfile << ip << "\n";
                }
                outfile.close();
            }
            
            // 进度显示
            if (i % 100 == 0) {
                std::cout << "已写入 " << i << "/" << PARTITION_COUNT << " 个分区文件" << std::endl;
            }
        }
        
        std::cout << "日志文件分割完成：" << std::endl;
        std::cout << "  - 总行数: " << processed_count << std::endl;
        std::cout << "  - 有效IP数量: " << valid_ip_count << std::endl;
        std::cout << "  - 无效行数: " << invalid_lines << std::endl;
        std::cout << "  - 非空分区: " << non_empty_partitions << "/" << PARTITION_COUNT << std::endl;
        
        return true;
    }
    
    /**
     * @brief 统计单个分割文件中IP地址的出现频次
     * 
     * 使用unordered_map进行高效统计，返回该文件中出现次数最多的IP及其次数
     * 
     * @param filename 分割文件名
     * @return pair<IP地址, 出现次数>，如果文件为空返回{"", 0}
     */
    static std::pair<std::string, size_t> analyzePartitionFile(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            // 文件不存在或为空
            return {"", 0};
        }
        
        std::unordered_map<std::string, size_t> ip_count;
        std::string ip;
        
        // 统计每个IP的出现次数
        while (std::getline(infile, ip)) {
            // 去除行尾空白字符
            while (!ip.empty() && (ip.back() == '\r' || ip.back() == '\n' || ip.back() == ' ')) {
                ip.pop_back();
            }
            
            if (!ip.empty()) {
                ip_count[ip]++;
            }
        }
        infile.close();
        
        if (ip_count.empty()) {
            return {"", 0};
        }
        
        // 找到出现次数最多的IP
        auto max_element = std::max_element(ip_count.begin(), ip_count.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            });
        
        return {max_element->first, max_element->second};
    }
    
    /**
     * @brief 主函数：分析超大日志文件，找到出现次数最多的IP地址
     * 
     * 完整的三步算法：
     * 1. 哈希分割：将大日志文件分割成多个小文件
     * 2. 分别统计：统计每个小文件中出现次数最多的IP
     * 3. 全局合并：找到全局出现次数最多的IP
     * 
     * @param log_file_path 日志文件路径
     * @param result_file_path 结果文件路径（可选）
     * @return pair<最高频次IP地址, 出现次数>
     */
    static std::pair<std::string, size_t> findMostFrequentIP(const std::string& log_file_path, 
                                                             const std::string& result_file_path = "") {
        auto start_time = std::chrono::high_resolution_clock::now();
        
        std::cout << "========================================" << std::endl;
        std::cout << "开始超大日志文件IP频次分析" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "日志文件: " << log_file_path << std::endl;
        std::cout << "内存限制: " << (MEMORY_LIMIT / (1024*1024)) << " MB" << std::endl;
        std::cout << "分割数量: " << PARTITION_COUNT << " 个小文件" << std::endl;
        std::cout << "========================================" << std::endl;
        
        // 步骤1: 哈希分割日志文件
        std::cout << "\n【步骤1/3】哈希分割日志文件..." << std::endl;
        if (!partitionLogFile(log_file_path, "log_part")) {
            std::cerr << "错误：分割日志文件失败" << std::endl;
            return {"", 0};
        }
        
        // 步骤2: 分析每个分割文件
        std::cout << "\n【步骤2/3】分析各个分割文件..." << std::endl;
        std::vector<std::pair<std::string, size_t>> partition_results;
        
        for (size_t i = 0; i < PARTITION_COUNT; ++i) {
            std::string part_filename = "log_part_" + std::to_string(i) + ".txt";
            auto result = analyzePartitionFile(part_filename);
            
            if (result.second > 0) {  // 只保存非空结果
                partition_results.push_back(result);
            }
            
            // 清理临时文件
            std::remove(part_filename.c_str());
            
            if (i % 100 == 0) {
                std::cout << "已分析 " << i << "/" << PARTITION_COUNT << " 个分割文件" << std::endl;
            }
        }
        
        // 步骤3: 找到全局最高频次IP
        std::cout << "\n【步骤3/3】合并统计结果..." << std::endl;
        
        if (partition_results.empty()) {
            std::cout << "未找到任何有效的IP地址" << std::endl;
            return {"", 0};
        }
        
        // 找到全局最高频次的IP
        auto global_max = *std::max_element(partition_results.begin(), partition_results.end(),
            [](const std::pair<std::string, size_t>& a, const std::pair<std::string, size_t>& b) {
                return a.second < b.second;
            });
        
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "IP频次分析完成！" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "最高频次IP地址: " << global_max.first << std::endl;
        std::cout << "出现次数: " << global_max.second << std::endl;
        std::cout << "分析的分区数: " << partition_results.size() << "/" << PARTITION_COUNT << std::endl;
        std::cout << "总耗时: " << duration.count() << " 秒" << std::endl;
        
        // 保存结果到文件（如果指定了结果文件路径）
        if (!result_file_path.empty()) {
            std::ofstream result_file(result_file_path);
            if (result_file.is_open()) {
                result_file << "最高频次IP分析结果\n";
                result_file << "==================\n";
                result_file << "IP地址: " << global_max.first << "\n";
                result_file << "出现次数: " << global_max.second << "\n";
                result_file << "分析时间: " << duration.count() << " 秒\n";
                result_file << "\n详细统计:\n";
                
                // 按频次降序排列所有结果
                std::sort(partition_results.begin(), partition_results.end(),
                    [](const std::pair<std::string, size_t>& a, const std::pair<std::string, size_t>& b) {
                        return a.second > b.second;
                    });
                
                for (size_t i = 0; i < std::min(partition_results.size(), size_t(20)); ++i) {
                    result_file << "第" << (i+1) << "名: " << partition_results[i].first 
                               << " (出现 " << partition_results[i].second << " 次)\n";
                }
                
                result_file.close();
                std::cout << "详细结果已保存到: " << result_file_path << std::endl;
            }
        }
        
        std::cout << "========================================" << std::endl;
        
        return global_max;
    }
    
    /**
     * @brief 生成测试日志文件
     * @param filename 文件名
     * @param line_count 日志行数
     * @param unique_ip_count 唯一IP数量
     * @param hot_ip_ratio 热点IP的出现比例（0.0-1.0）
     */
    static bool generateTestLogFile(const std::string& filename, 
                                   size_t line_count, 
                                   size_t unique_ip_count = 10000,
                                   double hot_ip_ratio = 0.3) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "错误：无法创建测试日志文件 " << filename << std::endl;
            return false;
        }
        
        std::cout << "生成测试日志文件: " << filename << std::endl;
        std::cout << "  - 日志行数: " << line_count << std::endl;
        std::cout << "  - 唯一IP数: " << unique_ip_count << std::endl;
        std::cout << "  - 热点IP比例: " << (hot_ip_ratio * 100) << "%" << std::endl;
        
        // 生成IP地址池
        std::vector<std::string> ip_pool;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> ip_dist(1, 254);
        
        for (size_t i = 0; i < unique_ip_count; ++i) {
            std::string ip = std::to_string(ip_dist(gen)) + "." + 
                           std::to_string(ip_dist(gen)) + "." + 
                           std::to_string(ip_dist(gen)) + "." + 
                           std::to_string(ip_dist(gen));
            ip_pool.push_back(ip);
        }
        
        // 创建热点IP（前几个IP会更频繁出现）
        size_t hot_ip_count = static_cast<size_t>(unique_ip_count * hot_ip_ratio);
        std::uniform_int_distribution<> hot_dist(0, hot_ip_count - 1);
        std::uniform_int_distribution<> normal_dist(0, unique_ip_count - 1);
        std::uniform_int_distribution<> choice_dist(1, 100);
        
        // 生成日志行
        for (size_t i = 0; i < line_count; ++i) {
            std::string ip;
            
            // 70%概率选择热点IP，30%概率选择普通IP
            if (choice_dist(gen) <= 70 && hot_ip_count > 0) {
                ip = ip_pool[hot_dist(gen)];
            } else {
                ip = ip_pool[normal_dist(gen)];
            }
            
            // 生成类似真实日志的格式
            file << ip << " - - [01/Jan/2024:12:00:00 +0000] \"GET /index.html HTTP/1.1\" 200 1024\n";
            
            if (i % 100000 == 0 && i > 0) {
                std::cout << "已生成 " << i << " 行日志..." << std::endl;
            }
        }
        
        std::cout << "测试日志文件生成完成: " << filename << std::endl;
        return true;
    }
};

/**
 * @brief 测试IP频次分析算法
 */
void test_ip_frequency_analysis() {
    std::cout << "\n=== 测试超大日志文件IP频次分析算法 ===" << std::endl;
    
    // 生成测试日志文件（规模适中用于演示）
    const size_t test_log_lines = 1000000; // 100万行日志
    const size_t unique_ips = 50000;       // 5万个唯一IP
    
    std::cout << "生成测试日志数据..." << std::endl;
    
    if (!IPFrequencyAnalyzer::generateTestLogFile("test_access.log", test_log_lines, unique_ips, 0.2)) {
        return;
    }
    
    // 执行IP频次分析
    auto result = IPFrequencyAnalyzer::findMostFrequentIP("test_access.log", "ip_analysis_result.txt");
    
    if (!result.first.empty()) {
        std::cout << "\n测试完成！" << std::endl;
        std::cout << "最高频次IP: " << result.first << " (出现 " << result.second << " 次)" << std::endl;
        std::cout << "详细结果请查看 ip_analysis_result.txt 文件" << std::endl;
    } else {
        std::cout << "\n测试失败！未找到有效IP地址" << std::endl;
    }
    
    // 清理测试文件
    std::cout << "\n清理临时文件..." << std::endl;
    std::remove("test_access.log");
}

} // namespace IPAnalysis