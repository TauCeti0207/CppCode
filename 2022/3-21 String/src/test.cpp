#include <string>
#include <iostream>
#include <string.h>
using namespace std;
void Test1()
{
    string s1;
    string s2("hello world");
    string s3(s2);
    string s4 = "hello world"; //隐式类型转换
    string s5(s4, 0, 3);
    cout << s5 << endl; // hel
    string s6(s4, 3, 15);
    cout << s6 << endl; // lo world
    string s7(s4, 3, string::npos);
    cout << s7 << endl; // lo world
}

void Test2()
{
    string s1("hello world");
    for (size_t i = 0; i < s1.size(); ++i)
    {
        cout << s1[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < s1.size(); ++i)
    {
        cout << s1.at(i) << " ";
    }
    cout << endl;
    // s1[20];
    try
    {
        s1.at(10);
    }
    catch (exception &e)
    {
        cout << e.what() << '\n';
    }
}

void Test3()
{
    string s1("hello world");
    string::iterator it = s1.begin();
    while (it != s1.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
void Test4()
{
    string s1("123456");
    string::iterator it = s1.begin();
    while (it != s1.end())
    {
        *it += 5;
        ++it;
    }
    string::reverse_iterator rit = s1.rbegin();
    while (rit != s1.rend())
    {
        cout << *rit << " "; //; : 9 8 7 6
        ++rit;
    }
    cout << endl;
}
void Test5()
{
    string s1("123456");
    for (char &e : s1)
    {
        e += 1;
        cout << e << " "; // 2 3 4 5 6 7
    }
    cout << endl;
}
void Test6()
{
    string s1;
    // s1.push_back('h');
    // s1.push_back('e');
    // s1.push_back('l');
    // s1.push_back('l');
    // s1.push_back('o');
    // s1.push_back(' ');

    // s1.append("world");
    // string s2("!!!");
    // s1.append(s2);
    // // s1.append(s2.begin(), s2.end()); //迭代器的写法，和append(s2)相同
    // cout << s1 << endl; // hello world!!!
    s1 += "hello";
    s1 += " ";
    s1 += "world";
    cout << s1 << endl; // hello world
}
void Test7()
{
    string s1 = "";
    s1.insert(0, "x");
    s1.insert(0, "xyy");
    cout << s1 << endl; // xyyx、
    s1.erase(0, 1);
    cout << s1 << endl; // yyx
    s1.erase(0, 2);
    cout << s1 << endl; // x
}
void Test8()
{
    string s1 = "";
    s1.insert(0, "x");
    s1.insert(0, "xyy");
    cout << s1 << endl; // xyyx、
    s1.erase(0);        //表示删完，默认参数是npos
    // s1.erase(0, 100); 这样也是删完了，毕竟只有4个字符
    cout << s1 << endl;
}

void Test9()
{
    string s1;
    string s2 = "hello world";
    cout << s1.max_size() << endl; // 4611686018427387903
    // 64 位环境下int的最大值。
    cout << s2.max_size() << endl; // 4611686018427387903
    cout << s1.size() << endl;     // 0
    cout << s2.size() << endl;     // 11
    cout << s1.capacity() << endl; // 15
    cout << s2.capacity() << endl; // 15

    s2.clear();
    cout << s2.size() << endl; // 0
    cout << s2 << endl;
    cout << s2.capacity() << endl; // 15
}

void Test10()
{
    string s1;
    cout << "s1.size():" << s1.size() << endl;
    cout << "s1.capacity():" << s1.capacity() << endl;
    cout << s1 << endl;

    s1.resize(20, 'x');
    cout << "s1.size():" << s1.size() << endl;
    cout << "s1.capacity():" << s1.capacity() << endl;
    cout << s1 << endl;
    // s1.size():0
    // s1.capacity():15

    // s1.size():20
    // s1.capacity():30
    // xxxxxxxxxxxxxxxxxxxx

    string s2("hello world");
    s2.resize(20, 'x');
    cout << s2 << endl; // hello worldxxxxxxxxx

    s2.resize(5);
    cout << s2 << endl; // hello
}
class Solution
{
public:
    int firstUniqChar(const string &s)
    {
        //哈希的思想
        int countArr[26] = {0}; //只有26个小写字母
        string::const_iterator it = s.begin();
        while (it != s.end())
        {
            //*it += 1; 无法修改
            countArr[*it - 'a']++;
        }
        for (size_t i = 0; i < s.size(); ++i)
            if (countArr[s[i] - 'a'] == 1)
                return (int)i; // i是size_t类型
        return -1;
    }
};
void Test11()
{
    string s1;
    cout << "s1.size():" << s1.size() << endl;
    cout << "s1.capacity():" << s1.capacity() << endl;
    s1.reserve(28);
    cout << "s1.size():" << s1.size() << endl;
    cout << "s1.capacity():" << s1.capacity() << endl;
    // s1.size():0
    // s1.capacity():15
    // s1.size():0
    // s1.capacity():30
}
void Test12()
{
    string s1;
    s1.reserve(127);
    int oldCapacity = s1.capacity();
    // char 范围是0~127 -128~-1
    for (char ch = 0; ch < 127; ++ch)
    {
        s1 += ch;
        if (oldCapacity != s1.capacity())
        {
            cout << "增容：" << oldCapacity << "->" << s1.capacity() << endl;
            oldCapacity = s1.capacity();
        }
    }
    cout << s1 << endl;
}
void Test13()
{
    string s1("hello world");
    cout << s1 << endl; //调用 operator<<(cout, s1)
    // hello world
    cout << s1.c_str() << endl; //调用 operator<<(cout, const char*)
    // hello world

    s1.resize(20);
    s1 += "!!!";
    cout << s1 << endl; //调用 operator<<(cout, s1)
    // hello world         !!!
    cout << s1.c_str() << endl; //调用 operator<<(cout, const char*)
    // hello world

    cout << strlen(s1.c_str()) << endl; // 11
    cout << s1.size() << endl;          // 23
}
// 要求取出文件名的后缀
void Test14()
{
    string fileName = "test.cpp.zip";
    size_t pos = fileName.rfind('.');
    if (pos != string::npos)
    {
        // string stuff(fileName, pos, fileName.size()-1);
        // string stuff = fileName.substr(pos, fileName.size() - 1);
        string stuff = fileName.substr(pos);
        cout << stuff << endl; //.zip
    }
}

//获取协议
string GetProtocol(const string &url)
{
    size_t pos = url.find("://");
    if (pos != string::npos)
    {
        return url.substr(0, pos);
    }
    else
    {
        // string s;
        // return s;//这样写比较麻烦
        return string(); //直接返回匿名对象，也就是空字符串。
    }
}
//获取域名
string GetDomain(const string &url)
{
    size_t pos = url.find("://");
    if (pos != string::npos)
    {
        size_t start = pos + 3;
        size_t end = url.find('/', start);
        if (end != string::npos)
        {
            return url.substr(start, end - start);
        }
        else
        {
            return string();
        }
    }
    else
    {
        return string();
    }
}
void Test15()
{
    string url1 = "https://cplusplus.com/reference/string/string/rfind/";
    string url2 = "https://leetcode-cn.com/problems/intersection-of-two-linked-lists/";
    cout << GetDomain(url1) << endl;
    cout << GetDomain(url2) << endl;
    cout << GetProtocol(url1) << endl;
    cout << GetProtocol(url1) << endl;
    // cplusplus.com
    // leetcode-cn.com
    // https
    // https
}
int main(int argc, char const *argv[])
{
    Test15();
    system("pause");
    return 0;
}
