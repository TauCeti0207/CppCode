#include "test.h"
#include "singleList.h"

// 自定义命名空间 yzq
namespace yzq
{
	// 命名空间内部定义的变量，为了避免与标准库函数名冲突，进行了重命名
	int customScanf = 0;
	int customStrlen = 10;

	// 定义链表节点结构体
	struct ListNode
	{
		int val;
		ListNode *next;
	};

	// 定义加法函数，返回 (a + b) * 10 的结果
	int Add(int a, int b)
	{
		return (a + b) * 10;
	}

	// 带有缺省参数的函数
	int AddWithDefault(int a, int b = 5)
	{
		return (a + b);
	}

	void defaultFun1(int a)
	{
		std::cout << "defaultFun1:" << a << std::endl;
	}

}

// 原有的函数重载
int CalculateSum(int left = 10, int right = 20)
{
	return left + right;
}

char CalculateSum(char left, char right)
{
	return left + right;
}

double CalculateSum(double left, double right)
{
	return left + right;
}

double CalculateSum(long left, long right)
{
	return left + right;
}

// 新增的函数重载，接收三个 int 类型的参数
int CalculateSum(int left, int right, int third)
{
	return left + right + third;
}

// 测试函数重载的函数
void TestFunctionOverloading()
{
	std::cout << "开始测试函数重载..." << std::endl;
	std::cout << "调用 CalculateSum()，结果为：" << CalculateSum() << std::endl;
	std::cout << "调用 CalculateSum(1, 2)，结果为：" << CalculateSum(1, 2) << std::endl;
	std::cout << "调用 CalculateSum('1', '2')，结果为：" << CalculateSum('1', '2') << std::endl;
	std::cout << "调用 CalculateSum(1.1, 2.2)，结果为：" << CalculateSum(1.1, 2.2) << std::endl;
	std::cout << "调用 CalculateSum(10L, 20L)，结果为：" << CalculateSum(10L, 20L) << std::endl;
	std::cout << "调用新增的 CalculateSum(1, 2, 3)，结果为：" << CalculateSum(1, 2, 3) << std::endl;
	std::cout << "函数重载测试结束。" << std::endl;
	std::cout << std::endl;
}

// 全局作用域的加法函数，返回 a + b 的结果
int GlobalAdd(int a, int b)
{
	return a + b;
}

// 嵌套命名空间 S1::S2
namespace S1
{
	namespace S2
	{
		int x;
		void FunA()
		{
			std::cout << "Inside S1::S2::FunA()" << std::endl;
		}
	}
}

// 测试命名空间使用的函数
void TestNamespaceUsage()
{
	std::cout << "开始测试自定义命名空间 yzq 的使用..." << std::endl;
	// 默认访问的是局部或全局
	// %p 打印指针的地址，这里输出全局 scanf 函数的地址
	printf("访问全局变量 scanf 函数的地址：");
	printf("%p\n", (void *)scanf);

	// 指定访问 yzq 空间中的 customScanf 变量
	printf("访问 yzq 空间中的 customScanf 变量的值：");
	printf("%x\n", yzq::customScanf);

	// 访问命名空间 yzq 中的 Add 函数
	printf("访问命名空间的函数：");
	printf("%d\n", yzq::Add(1, 2));

	// 访问全局作用域的 GlobalAdd 函数
	printf("访问全局函数：");
	printf("%d\n", GlobalAdd(1, 2));

	// 创建命名空间 yzq 中的 ListNode 结构体对象
	yzq::ListNode node;
	node.val = 10;
	node.next = nullptr;
	printf("访问命名空间中的结构体：node.val = %d\n", node.val);
	std::cout << "自定义命名空间 yzq 的使用测试结束。" << std::endl;
	std::cout << std::endl;
}

// 测试展开 S2 命名空间
void TestExpandS2Namespace()
{
	std::cout << "开始测试展开 S2 命名空间..." << std::endl;
	using S1::S2::FunA;
	S1::S2::x = 30;
	std::cout << "展开 S2 命名空间后访问变量 x: " << S1::S2::x << std::endl;
	FunA();
	std::cout << "S2 命名空间展开测试结束。" << std::endl;
	std::cout << std::endl;
}

// C++ 标准库使用命名空间 std
// 方式 1: 指定命名空间，不使用 using namespace std;
void TestStdNamespaceMethod1()
{
	std::cout << "开始测试使用标准库命名空间 std 的方式 1（指定命名空间）..." << std::endl;
	std::cout << "使用方式 1: 指定命名空间 输出 hello world" << std::endl;
	std::cout << "hello world" << std::endl;
	std::cout << "标准库命名空间 std 的方式 1 测试结束。" << std::endl;
	std::cout << std::endl;
}

// 方式 2: 把 std 整个展开
void TestStdNamespaceMethod2()
{
	std::cout << "开始测试使用标准库命名空间 std 的方式 2（整个展开）..." << std::endl;
	using namespace std;
	cout << "使用方式 2: 展开 std 命名空间 输出 hello world" << endl;
	cout << "hello world" << endl;
	std::cout << "标准库命名空间 std 的方式 2 测试结束。" << std::endl;
	std::cout << std::endl;
}

// 方式 3: 对部分常用的库里的东西展开
void TestStdNamespaceMethod3()
{
	std::cout << "开始测试使用标准库命名空间 std 的方式 3（部分展开）..." << std::endl;
	using std::cout;
	using std::endl;
	cout << "使用方式 3: 部分展开 std 命名空间 输出 hello world" << endl;
	cout << "hello world" << endl;
	std::cout << "标准库命名空间 std 的方式 3 测试结束。" << std::endl;
	std::cout << std::endl;
}

// 演示 cin 和 cout 的功能
void TestCinCoutFunctionality()
{
	std::cout << "开始演示 cin 和 cout 的功能..." << std::endl;
	std::cout << "hello world" << std::endl;
	// 对比C语言printf scanf 优势: 自动识别类型
	int a = 10;
	int *p = &a;
	// 自动识别类型原理：函数重载+运算符重载
	std::cout << a << "," << p << std::endl;
	char str[10];

	// >>流提取运算符
	std::cout << "请输入一个整数和一个字符串（以空格分隔）：";
	std::cin >> a;
	std::cin >> str;

	// <<流插入运算符
	std::cout << "你输入的整数是：" << a << "，输入的字符串是：" << str << std::endl;
	std::cout << "cin 和 cout 的功能演示结束。" << std::endl;
	std::cout << std::endl;
}

// 测试缺省参数的函数
void TestDefaultParameter()
{
	std::cout << "开始测试缺省参数函数..." << std::endl;
	// 只传入一个参数，使用缺省参数
	int result1 = yzq::AddWithDefault(3);
	std::cout << "调用 yzq::AddWithDefault(3) ，使用缺省参数，结果为：" << result1 << std::endl;

	// 传入两个参数，不使用缺省参数
	int result2 = yzq::AddWithDefault(3, 4);
	std::cout << "调用 yzq::AddWithDefault(3, 4) ，不使用缺省参数，结果为：" << result2 << std::endl;

	yzq::defaultFun1(1);

	std::cout << "缺省参数函数测试结束。" << std::endl;
	std::cout << std::endl;
}

namespace yzq1
{
	int Add(int a, int b)
	{
		return a + b;
	}
}

namespace yzq2
{
	int Add(int a, int b)
	{
		return a + b;
	}

	int Add(int a, char b)
	{
		return a + b;
	}
}

void TestFunOverLoadingPrinciple()
{
	std::cout << "通过反汇编测试函数重载原理..." << std::endl;
	std::cout << yzq2::Add(1, '2') << std::endl;
	std::cout << yzq2::Add(1, 2) << std::endl;
}

// 测试引用作为变量别名
void test_reference_as_alias()
{
	std::cout << "--- 测试引用作为变量别名 ---" << std::endl;
	int num = 10;
	std::cout << "原始变量 num 的值: " << num << std::endl;

	int &ref = num;
	ref = 20;
	std::cout << "通过引用 ref 修改后，num 的值: " << num << std::endl;
	assert(num == 20);
	std::cout << "测试通过！" << std::endl;

	// 一个变量可以有多个别名
	std::cout << "一个变量可以有多个别名: " << std::endl;
	int &ref2 = num;
	int &ref3 = ref;
	std::cout << "ref2 和 ref3 的值: " << ref2 << " " << ref3 << std::endl;
}

// 交换函数，使用引用作为参数
void Swap(int &r1, int &r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

// 测试引用在交换函数中的基本使用
void test_swap_with_reference_basic()
{
	std::cout << "--- 测试引用在交换函数中的基本使用 ---" << std::endl;
	int x = 1, y = 2;
	std::cout << "交换前，x: " << x << ", y: " << y << std::endl;

	Swap(x, y);
	std::cout << "交换后，x: " << x << ", y: " << y << std::endl;

	assert(x == 2 && y == 1);
	std::cout << "测试通过！" << std::endl;
}

// 测试单链表插入操作的函数
void testSingleListPushBack()
{
	std::cout << "--- 开始测试单链表插入操作 ---" << std::endl;
	PListNode head = nullptr;

	std::cout << "插入元素 1:" << std::endl;
	PushBack(head, 1);
	std::cout << "当前链表元素: ";
	PrintList(head);

	std::cout << "插入元素 2:" << std::endl;
	PushBack(head, 2);
	std::cout << "当前链表元素: ";
	PrintList(head);

	std::cout << "插入元素 3:" << std::endl;
	PushBack(head, 3);
	std::cout << "当前链表元素: ";
	PrintList(head);

	std::cout << "--- 单链表插入操作测试结束 ---" << std::endl;
}

// 测试引用初始化
void test_reference_initialization()
{
	std::cout << "--- 测试引用初始化 ---" << std::endl;
	int num = 10;
	// 正常初始化引用
	int &ref = num;
	std::cout << "引用 ref 初始化为 num，ref 的值: " << ref << std::endl;

	// 这里不能再让 ref 引用其他变量，若尝试会编译错误
	// 下面代码若取消注释会导致编译错误
	// int anotherNum = 20;
	// ref = anotherNum;

	std::cout << "测试通过！（注意：尝试重新绑定引用会导致编译错误）" << std::endl;
}

// 测试常量引用作为函数参数
void printValue(const int &value)
{
	std::cout << "常量引用的值: " << value << std::endl;
	// 下面代码若取消注释会导致编译错误，因为常量引用不能修改
	// value = 30;
}

void test_const_reference_as_function_parameter()
{
	std::cout << "--- 测试常量引用作为函数参数 ---" << std::endl;
	int num = 10;
	const int constNum = 20;

	printValue(num);
	printValue(constNum);
	std::cout << "测试通过！（注意：尝试修改常量引用会导致编译错误）" << std::endl;
}

// 5. 测试返回引用的函数
int &getMax(int &a, int &b)
{
	return (a > b) ? a : b;
}

void test_function_returning_reference()
{
	std::cout << "--- 测试返回引用的函数 ---" << std::endl;
	int x = 10;
	int y = 20;
	std::cout << "调用函数前，x: " << x << ", y: " << y << std::endl;

	int &maxRef = getMax(x, y);
	maxRef = 30;
	std::cout << "通过返回的引用修改后，x: " << x << ", y: " << y << std::endl;
	assert(y == 30);
	std::cout << "测试通过！" << std::endl;
}

// 6. 测试引用和指针的区别
void test_reference_vs_pointer()
{
	std::cout << "--- 测试引用和指针的区别 ---" << std::endl;
	int num = 10;
	int &ref = num;
	int *ptr = &num;

	std::cout << "引用 ref 的值: " << ref << ", 指针 ptr 指向的值: " << *ptr << std::endl;

	// 指针可以为 nullptr
	ptr = nullptr;
	std::cout << "将指针 ptr 置为 nullptr" << std::endl;

	// 但引用一旦初始化就不能再引用其他对象
	// 下面代码若取消注释会导致编译错误
	// int anotherNum = 20;
	// ref = anotherNum;

	std::cout << "测试通过！（注意：尝试重新绑定引用会导致编译错误）" << std::endl;
}

// 7. 测试引用数组
void test_reference_array()
{
	std::cout << "--- 测试引用数组 ---" << std::endl;
	int arr[3] = {1, 2, 3};
	int (&refArr)[3] = arr;

	std::cout << "引用数组的元素: ";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << refArr[i] << " ";
	}
	std::cout << std::endl;

	refArr[1] = 10;
	std::cout << "修改引用数组元素后，原数组的元素: ";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	assert(arr[1] == 10);
	std::cout << "测试通过！" << std::endl;
}

// 8. 测试引用在类中的使用
class MyClass
{
public:
	MyClass(int &value) : ref(value) {}
	void printRefValue()
	{
		std::cout << "类中引用的值: " << ref << std::endl;
	}
	void modifyRefValue(int newVal)
	{
		ref = newVal;
	}

private:
	int &ref;
};

void test_reference_in_class()
{
	std::cout << "--- 测试引用在类中的使用 ---" << std::endl;
	int num = 10;
	MyClass obj(num);
	obj.printRefValue();

	obj.modifyRefValue(20);
	std::cout << "通过类方法修改引用后，原变量 num 的值: " << num << std::endl;
	assert(num == 20);
	std::cout << "测试通过！" << std::endl;
}

int main(int argc, char const *argv[])
{
	// 测试自定义命名空间 yzq
	// TestNamespaceUsage();

	// 测试展开 S2 命名空间
	// TestExpandS2Namespace();

	// 测试使用标准库命名空间 std 的三种方式
	// TestStdNamespaceMethod1();
	// TestStdNamespaceMethod2();
	// TestStdNamespaceMethod3();

	// 测试 cin 和 cout 的功能
	// TestCinCoutFunctionality();

	// 测试缺省参数的函数
	// TestDefaultParameter();

	// 测试函数重载
	// TestFunctionOverloading();

	// 测试函数重载原理
	// TestFunOverLoadingPrinciple();

	// test_reference_as_alias();
	// test_swap_with_reference_basic();
	testSingleListPushBack();
	return 0;
}