// #include <iostream>
// using namespace std;
// //C++兼容C的语法
// int main(int argc, char const *argv[])
// {
//     cout << "hello wordld" << endl;
//     return 0;
// }

// namespace 定义一个域
//本质是解决C语言命名冲突问题
// #include <stdio.h>
// #include <windows.h>
// #include "List.h"
// //C++利用命名空间的机制

// // int main(int argc, char const *argv[])
// // {
// //     //命名冲突
// //     //c语言库里面,有2个函数用了scanf 和strlen名称
// //     // int scanf = 0;
// //     // int strlen = 10;
// //     //变量定义时能通过,但下面调用scanf时就不行,调用scanf是就近读取
// //     //C语言解决不了这个冲突问题
// //     //scanf("%d ",&scanf);
// //     printf("%p\n",scanf);
// //     system("pause");
// //     return 0;
// // }

// namespace yzq
// {
//     int scanf = 0;
//     int strlen = 10;
// }
// int main(int argc, char const *argv[])
// {
//     //默认访问的是局部或全局
//     printf("%x\n",scanf); //2d312e90 结果就是scanf函数的地址
//     //搜索scanf时是就近原则,不会到namespace里面去搜索,就近找不到就去全局搜索,头文件里找

//     //指定访问yzq空间中的
//     printf("%x\n",yzq::scanf); //0
//     printf("%d\n",bit::scanf); //30

//     bit::ListNode* pHead = NULL;
//     system("pause");
//     return 0;
// }

// namespace bit
// {
// 	int scanf = 10;
// 	int strlen = 20;

// 	int Add(int left, int right)
// 	{
// 		return left + right;
// 	}

// 	// 嵌套定义命名空间
// 	namespace N3
// 	{
// 		int c;
// 		int d;
// 		int Sub(int left, int right)
// 		{
// 			return left - right;
// 		}

// 		// 还可以再套
// 	}
// }

// C++库为了防止命名冲突,把自己库里面定义的东西都定义在一个std的命名空间中
//使用标准库中的东西 3种方式

// 1.指定命名空间 不使用 using namespace std;
//  int main(int argc, char const *argv[])
//  {
//      std::cout << "hello world" << std::endl;
//      system("pause");
//      return 0;
//  }

// using namespace std;
// C++兼容C的语法
//  int main(int argc, char const *argv[])
//  {
//      cout << "hello wordld" << endl;
//      system("pause");
//      return 0;
//  }

// 2.把std整个展开,相当于库里面的东西都到全局域了
//看起来方便了,但如果是我们自己定义的东西跟库冲突了就没法解决
//规范的工程项目中是不推荐这种方式的  日常练习比较方便
//  using namespace std;
//  int main(int argc, char const *argv[])
//  {
//      cout << "hello world" << endl;
//      system("pause");
//      return 0;
//  }

// //3.对部分常用的库里的东西展开
// //折中方案,项目中也经常用
// using std::cout;
// using std::cin;
// using std::endl;

#include <iostream>
#include <windows.h>

using namespace std;
int main(int argc, char const *argv[])
{
    cout << "hello world" << endl;
    //对比C语言printf scanf 优势: 自动识别类型
    int a = 10;
    system("pause");
    return 0;
}
