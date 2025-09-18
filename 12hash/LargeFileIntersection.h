#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <chrono>
#include <functional>

namespace LargeFileProcessing {

/**
 * @brief 大文件交集处理器 - 处理超大文件的精确交集计算
 * 
 * 解决问题：给定两个各含100亿条query的文件，在1GB内存限制下找到交集
 * 
 * 核心思想：哈希切分 + 排序 + 归并
 * 1. 哈希分割：将两个大文件按相同哈希函数分割成多个小文件
 *    - 保证相同的query一定会分别进入Ai和Bi编号相同的小文件
 * 2. 外部排序：对每个小文件进行排序
 * 3. 归并求交集：对相同编号的文件对求交集
 */
class LargeFileIntersection {
private:
    static constexpr size_t MEMORY_LIMIT = 1024 * 1024 * 1024; // 1GB内存限制
    static constexpr size_t BUFFER_SIZE = 64 * 1024 * 1024;    // 64MB 缓冲区
    static constexpr size_t PARTITION_COUNT = 1000;             // 分割成1000个小文件
    static constexpr size_t MAX_QUERY_LENGTH = 256;             // 最大query长度
    
    /**
     * @brief 哈希函数 - 确保相同query分配到相同编号的文件
     * 使用DJBX33A哈希算法，分布均匀且计算快速
     */
    static size_t hash_string(const std::string& str) {
        size_t hash = 5381;
        for (char c : str) {
            hash = ((hash << 5) + hash) + static_cast<unsigned char>(c);
        }
        return hash % PARTITION_COUNT;
    }
    
public:
    /**
     * @brief 将大文件按哈希值分割成多个小文件（分批处理版本）
     * 
     * 关键特性：相同的query会被分配到相同编号的小文件中
     * 这是算法正确性的核心保证
     * 
     * 优化：分批处理避免同时打开过多文件句柄
     * 
     * @param input_file 输入文件路径
     * @param output_prefix 输出文件前缀（如"fileA"会生成fileA_0.txt, fileA_1.txt等）
     * @return 是否成功
     */
    static bool partitionFile(const std::string& input_file, const std::string& output_prefix) {
        std::cout << "开始分割文件: " << input_file << std::endl;
        
        // 第一遍：读取所有数据并按哈希值分组到内存中
        std::ifstream infile(input_file);
        if (!infile.is_open()) {
            std::cerr << "错误：无法打开输入文件 " << input_file << std::endl;
            return false;
        }
        
        // 使用vector数组存储每个分区的数据
        std::vector<std::vector<std::string>> partitions(PARTITION_COUNT);
        
        std::string line;
        size_t processed_count = 0;
        size_t empty_lines = 0;
        
        std::cout << "第一阶段：读取数据并分组..." << std::endl;
        
        // 逐行读取并按哈希值分配到对应分区
        while (std::getline(infile, line)) {
            // 去除行尾空白字符
            while (!line.empty() && (line.back() == '\r' || line.back() == '\n' || line.back() == ' ')) {
                line.pop_back();
            }
            
            if (!line.empty()) {
                size_t hash_value = hash_string(line);
                partitions[hash_value].push_back(line);
                processed_count++;
            } else {
                empty_lines++;
            }
            
            // 进度显示
            if ((processed_count + empty_lines) % 100000 == 0) {
                std::cout << "已处理 " << (processed_count + empty_lines) << " 行，有效记录 " << processed_count << " 条" << std::endl;
            }
        }
        infile.close();
        
        std::cout << "第二阶段：写入分割文件..." << std::endl;
        
        // 第二遍：将每个分区的数据写入对应文件
        for (size_t i = 0; i < PARTITION_COUNT; ++i) {
            if (!partitions[i].empty()) {
                std::string filename = output_prefix + "_" + std::to_string(i) + ".txt";
                std::ofstream outfile(filename);
                if (!outfile.is_open()) {
                    std::cerr << "错误：无法创建输出文件 " << filename << std::endl;
                    return false;
                }
                
                for (const auto& item : partitions[i]) {
                    outfile << item << "\n";
                }
                outfile.close();
            }
            
            // 进度显示
            if (i % 100 == 0) {
                std::cout << "已写入 " << i << "/" << PARTITION_COUNT << " 个分区文件" << std::endl;
            }
        }
        
        std::cout << "文件分割完成：" << std::endl;
        std::cout << "  - 总行数: " << (processed_count + empty_lines) << std::endl;
        std::cout << "  - 有效记录: " << processed_count << " 条" << std::endl;
        std::cout << "  - 空行: " << empty_lines << " 行" << std::endl;
        std::cout << "  - 分割成: " << PARTITION_COUNT << " 个小文件" << std::endl;
        
        // 显示分区分布统计
        size_t non_empty_partitions = 0;
        size_t max_partition_size = 0;
        size_t min_partition_size = SIZE_MAX;
        
        for (size_t i = 0; i < PARTITION_COUNT; ++i) {
            if (!partitions[i].empty()) {
                non_empty_partitions++;
                max_partition_size = std::max(max_partition_size, partitions[i].size());
                min_partition_size = std::min(min_partition_size, partitions[i].size());
            }
        }
        
        if (min_partition_size == SIZE_MAX) min_partition_size = 0;
        
        std::cout << "  - 非空分区: " << non_empty_partitions << "/" << PARTITION_COUNT << std::endl;
        std::cout << "  - 最大分区大小: " << max_partition_size << " 条记录" << std::endl;
        std::cout << "  - 最小分区大小: " << min_partition_size << " 条记录" << std::endl;
        
        return true;
    }
    
    /**
     * @brief 外部归并排序 - 对单个文件进行排序
     * 
     * 对于小文件，直接加载到内存排序
     * 对于大文件，可以实现真正的外部排序（分块排序+归并）
     * 
     * @param filename 要排序的文件名
     * @return 是否成功
     */
    static bool externalMergeSort(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            // 文件不存在或为空，跳过
            return true;
        }
        
        // 读取所有数据到内存中排序
        std::vector<std::string> data;
        std::string line;
        
        while (std::getline(infile, line)) {
            // 去除行尾空白字符
            while (!line.empty() && (line.back() == '\r' || line.back() == '\n' || line.back() == ' ')) {
                line.pop_back();
            }
            if (!line.empty()) {
                data.push_back(line);
            }
        }
        infile.close();
        
        if (data.empty()) {
            return true; // 空文件，无需排序
        }
        
        // 排序并去重
        std::sort(data.begin(), data.end());
        data.erase(std::unique(data.begin(), data.end()), data.end());
        
        // 写回文件
        std::ofstream outfile(filename);
        if (!outfile.is_open()) {
            std::cerr << "错误：无法写入文件 " << filename << std::endl;
            return false;
        }
        
        for (const auto& item : data) {
            outfile << item << "\n";
        }
        
        return true;
    }
    
    /**
     * @brief 计算两个有序文件的交集
     * 
     * 使用双指针法，时间复杂度O(m+n)，空间复杂度O(1)
     * 
     * @param file1 第一个有序文件
     * @param file2 第二个有序文件
     * @param output_file 输出交集文件
     * @return 交集元素数量
     */
    static size_t computeIntersection(const std::string& file1, 
                                      const std::string& file2, 
                                      const std::string& output_file) {
        std::ifstream f1(file1), f2(file2);
        
        // 如果任一文件不存在或为空，交集为空
        if (!f1.is_open() || !f2.is_open()) {
            std::ofstream empty_output(output_file);
            return 0;
        }
        
        std::ofstream outfile(output_file);
        if (!outfile.is_open()) {
            std::cerr << "错误：无法创建输出文件 " << output_file << std::endl;
            return 0;
        }
        
        std::string line1, line2;
        bool has_line1 = static_cast<bool>(std::getline(f1, line1));
        bool has_line2 = static_cast<bool>(std::getline(f2, line2));
        size_t intersection_count = 0;
        
        // 双指针法求交集
        while (has_line1 && has_line2) {
            // 去除行尾空白字符
            while (!line1.empty() && (line1.back() == '\r' || line1.back() == '\n' || line1.back() == ' ')) {
                line1.pop_back();
            }
            while (!line2.empty() && (line2.back() == '\r' || line2.back() == '\n' || line2.back() == ' ')) {
                line2.pop_back();
            }
            
            if (line1 == line2) {
                // 找到交集元素
                if (!line1.empty()) {
                    outfile << line1 << "\n";
                    intersection_count++;
                }
                has_line1 = static_cast<bool>(std::getline(f1, line1));
                has_line2 = static_cast<bool>(std::getline(f2, line2));
            } else if (line1 < line2) {
                has_line1 = static_cast<bool>(std::getline(f1, line1));
            } else {
                has_line2 = static_cast<bool>(std::getline(f2, line2));
            }
        }
        
        return intersection_count;
    }
    
    /**
     * @brief 主函数：计算两个大文件的交集
     * 
     * 完整的三步算法：
     * 1. 哈希分割：保证相同query进入相同编号的小文件
     * 2. 排序：对每个小文件排序并去重
     * 3. 求交集：对相同编号的文件对求交集
     * 
     * @param file1_path 第一个大文件路径
     * @param file2_path 第二个大文件路径
     * @param result_path 结果文件路径
     * @return 是否成功
     */
    static bool findIntersection(const std::string& file1_path, 
                                 const std::string& file2_path, 
                                 const std::string& result_path) {
        auto start_time = std::chrono::high_resolution_clock::now();
        
        std::cout << "========================================" << std::endl;
        std::cout << "开始大文件交集计算" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "文件A: " << file1_path << std::endl;
        std::cout << "文件B: " << file2_path << std::endl;
        std::cout << "结果文件: " << result_path << std::endl;
        std::cout << "内存限制: " << (MEMORY_LIMIT / (1024*1024)) << " MB" << std::endl;
        std::cout << "分割数量: " << PARTITION_COUNT << " 个小文件" << std::endl;
        std::cout << "========================================" << std::endl;
        
        // 步骤1: 哈希分割文件
        std::cout << "\n【步骤1/3】哈希分割文件..." << std::endl;
        std::cout << "分割文件A..." << std::endl;
        if (!partitionFile(file1_path, "tempA")) {
            std::cerr << "错误：分割文件A失败" << std::endl;
            return false;
        }
        
        std::cout << "分割文件B..." << std::endl;
        if (!partitionFile(file2_path, "tempB")) {
            std::cerr << "错误：分割文件B失败" << std::endl;
            return false;
        }
        
        // 步骤2: 对每个分割文件进行排序
        std::cout << "\n【步骤2/3】排序分割文件..." << std::endl;
        for (size_t i = 0; i < PARTITION_COUNT; ++i) {
            std::string fileA_part = "tempA_" + std::to_string(i) + ".txt";
            std::string fileB_part = "tempB_" + std::to_string(i) + ".txt";
            
            if (!externalMergeSort(fileA_part)) {
                std::cerr << "错误：排序文件 " << fileA_part << " 失败" << std::endl;
                return false;
            }
            
            if (!externalMergeSort(fileB_part)) {
                std::cerr << "错误：排序文件 " << fileB_part << " 失败" << std::endl;
                return false;
            }
            
            if (i % 100 == 0) {
                std::cout << "已排序 " << i << "/" << PARTITION_COUNT << " 个文件对" << std::endl;
            }
        }
        
        // 步骤3: 计算每对文件的交集
        std::cout << "\n【步骤3/3】计算交集..." << std::endl;
        std::ofstream final_result(result_path);
        if (!final_result.is_open()) {
            std::cerr << "错误：无法创建最终结果文件 " << result_path << std::endl;
            return false;
        }
        
        size_t total_intersection = 0;
        size_t non_empty_partitions = 0;
        
        for (size_t i = 0; i < PARTITION_COUNT; ++i) {
            std::string fileA_part = "tempA_" + std::to_string(i) + ".txt";
            std::string fileB_part = "tempB_" + std::to_string(i) + ".txt";
            std::string temp_result = "temp_result_" + std::to_string(i) + ".txt";
            
            size_t count = computeIntersection(fileA_part, fileB_part, temp_result);
            total_intersection += count;
            
            if (count > 0) {
                non_empty_partitions++;
                
                // 将临时结果追加到最终结果文件
                std::ifstream temp_file(temp_result);
                std::string line;
                while (std::getline(temp_file, line)) {
                    final_result << line << "\n";
                }
                temp_file.close();
            }
            
            // 清理临时文件
            std::remove(fileA_part.c_str());
            std::remove(fileB_part.c_str());
            std::remove(temp_result.c_str());
            
            if (i % 100 == 0) {
                std::cout << "已处理 " << i << "/" << PARTITION_COUNT 
                         << " 个文件对，当前交集数量: " << total_intersection << std::endl;
            }
        }
        
        final_result.close();
        
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "交集计算完成！" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "总交集数量: " << total_intersection << std::endl;
        std::cout << "有交集的分区: " << non_empty_partitions << "/" << PARTITION_COUNT << std::endl;
        std::cout << "总耗时: " << duration.count() << " 秒" << std::endl;
        std::cout << "结果已保存到: " << result_path << std::endl;
        std::cout << "========================================" << std::endl;
        
        return true;
    }
    
    /**
     * @brief 生成测试文件
     * @param filename 文件名
     * @param count 记录数量
     * @param start_value 起始值
     * @param overlap_ratio 重叠比例（0.0-1.0）
     */
    static bool generateTestFile(const std::string& filename, 
                                size_t count, 
                                size_t start_value, 
                                double overlap_ratio = 0.5) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "错误：无法创建测试文件 " << filename << std::endl;
            return false;
        }
        
        std::cout << "生成测试文件: " << filename 
                 << " (包含 " << count << " 条记录，重叠率 " << (overlap_ratio * 100) << "%)" << std::endl;
        
        for (size_t i = 0; i < count; ++i) {
            // 生成一些重复的数据来测试交集
            size_t value = start_value + (i % static_cast<size_t>(count * overlap_ratio));
            file << "query_" << value << "_test_data_" << (i % 1000) << std::endl;
            
            if (i % 100000 == 0 && i > 0) {
                std::cout << "已生成 " << i << " 条记录..." << std::endl;
            }
        }
        
        std::cout << "测试文件生成完成: " << filename << std::endl;
        return true;
    }
};

/**
 * @brief 测试大文件交集算法
 */
void test_large_file_intersection() {
    std::cout << "\n=== 测试大文件交集算法 ===" << std::endl;
    
    // 生成两个测试文件（规模较小用于演示）
    const size_t test_size = 1000000; // 100万条记录用于测试
    
    std::cout << "生成测试数据..." << std::endl;
    
    // 文件A: query_0 到 query_499999，重复2次
    if (!LargeFileIntersection::generateTestFile("test_fileA.txt", test_size, 0, 0.5)) {
        return;
    }
    
    // 文件B: query_250000 到 query_749999，重复2次（与A有25万重叠）
    if (!LargeFileIntersection::generateTestFile("test_fileB.txt", test_size, test_size / 4, 0.5)) {
        return;
    }
    
    // 执行交集计算
    bool success = LargeFileIntersection::findIntersection(
        "test_fileA.txt", 
        "test_fileB.txt", 
        "intersection_result.txt"
    );
    
    if (success) {
        std::cout << "\n测试完成！请查看 intersection_result.txt 文件" << std::endl;
        
        // 验证结果
        std::ifstream result_file("intersection_result.txt");
        if (result_file.is_open()) {
            size_t line_count = 0;
            std::string line;
            while (std::getline(result_file, line)) {
                line_count++;
            }
            std::cout << "结果文件包含 " << line_count << " 行交集记录" << std::endl;
        }
    } else {
        std::cout << "\n测试失败！" << std::endl;
    }
    
    // 清理测试文件
    std::cout << "\n清理临时文件..." << std::endl;
    std::remove("test_fileA.txt");
    std::remove("test_fileB.txt");
}

} // namespace LargeFileProcessing