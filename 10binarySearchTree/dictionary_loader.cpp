#include "BinarySearchTree.h"
#include <fstream>
#include <string>
#include <iostream>

// 从文件加载词典
bool loadDictionaryFromFile(key_value::BSTree<std::string, std::string>& dict, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "无法打开文件: " << filename << std::endl;
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // 假设文件格式为: 英文,中文
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            std::string english = line.substr(0, pos);
            std::string chinese = line.substr(pos + 1);
            dict.InsertR(english, chinese);
        }
    }
    
    file.close();
    return true;
}

// 改进版的字典测试函数
void improvedDictionaryTest() {
    key_value::BSTree<std::string, std::string> EToCDict;
    
    // 加载基本词汇
    EToCDict.InsertR("root", "根");
    EToCDict.InsertR("left", "左边");
    EToCDict.InsertR("right", "右边");
    // ... 其他基本词汇
    
    // 从文件加载更多词汇
    std::cout << "正在从文件加载词典..." << std::endl;
    if (loadDictionaryFromFile(EToCDict, "dictionary.txt")) {
        std::cout << "词典加载成功！" << std::endl;
    }
    
    // 查询功能
    std::string str;
    std::cout << "请输入英文单词（输入'exit'退出）：" << std::endl;
    while (std::cin >> str && str != "exit") {
        key_value::BSTreeNode<std::string, std::string> *ret = EToCDict.FindR(str);
        if (ret != nullptr) {
            std::cout << "对应的中文: " << ret->_value << std::endl;
        } else {
            std::cout << "无此单词，请重新输入：" << std::endl;
        }
    }
} 