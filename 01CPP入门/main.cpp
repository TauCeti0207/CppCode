#include "test.h"
#include "singleList.h"
#include <time.h>

// 自定义命名空间 yzq
namespace yzq
{
	// 命名空间内部定义的变量，为了避免与标准库函数名冲突，进行了重命名
	int customScanf = 0;
	int customStrlen = 10;

	// 定义链表节点结构体
	struct listNode
	{
		int val;
		listNode *next;
	};

	// 定义加法函数，返回 (a + b) * 10 的结果
	int add(int a, int b)
	{
		return (a + b) * 10;
	}

	// 带有缺省参数的函数
	int addWithDefault(int a, int b = 5)
	{
		return (a + b);
	}

	void defaultFun1(int a)
	{
		std::cout << "defaultFun1:" << a << std::endl;
	}
}

// 原有的函数重载
int calculateSum(int left = 10, int right = 20)
{
	return left + right;
}

char calculateSum(char left, char right)
{
	return left + right;
}

double calculateSum(double left, double right)
{
	return left + right;
}

double calculateSum(long left, long right)
{
	return left + right;
}

// 新增的函数重载，接收三个 int 类型的参数
int calculateSum(int left, int right, int third)
{
	return left + right + third;
}

// 测试函数重载的函数
void testFunctionOverloading()
{
	std::cout << "开始测试函数重载..." << std::endl;
	std::cout << "调用 calculateSum()，结果为：" << calculateSum() << std::endl;
	std::cout << "调用 calculateSum(1, 2)，结果为：" << calculateSum(1, 2) << std::endl;
	std::cout << "调用 calculateSum('1', '2')，结果为：" << calculateSum('1', '2') << std::endl;
	std::cout << "调用 calculateSum(1.1, 2.2)，结果为：" << calculateSum(1.1, 2.2) << std::endl;
	std::cout << "调用 calculateSum(10L, 20L)，结果为：" << calculateSum(10L, 20L) << std::endl;
	std::cout << "调用新增的 calculateSum(1, 2, 3)，结果为：" << calculateSum(1, 2, 3) << std::endl;
	std::cout << "函数重载测试结束。" << std::endl;
	std::cout << std::endl;
}

// 全局作用域的加法函数，返回 a + b 的结果
int globalAdd(int a, int b)
{
	return a + b;
}

// 嵌套命名空间 S1::S2
namespace S1
{
	namespace S2
	{
		int x;
		void funA()
		{
			std::cout << "Inside S1::S2::funA()" << std::endl;
		}
	}
}

// 测试命名空间使用的函数
void testNamespaceUsage()
{
	std::cout << "开始测试自定义命名空间 yzq 的使用..." << std::endl;
	// 默认访问的是局部或全局
	// %p 打印指针的地址，这里输出全局 scanf 函数的地址
	printf("访问全局变量 scanf 函数的地址：");
	printf("%p\n", (void *)scanf);

	// 指定访问 yzq 空间中的 customScanf 变量
	printf("访问 yzq 空间中的 customScanf 变量的值：");
	printf("%x\n", yzq::customScanf);

	// 访问命名空间 yzq 中的 add 函数
	printf("访问命名空间的函数：");
	printf("%d\n", yzq::add(1, 2));

	// 访问全局作用域的 globalAdd 函数
	printf("访问全局函数：");
	printf("%d\n", globalAdd(1, 2));

	// 创建命名空间 yzq 中的 listNode 结构体对象
	yzq::listNode node;
	node.val = 10;
	node.next = nullptr;
	printf("访问命名空间中的结构体：node.val = %d\n", node.val);
	std::cout << "自定义命名空间 yzq 的使用测试结束。" << std::endl;
	std::cout << std::endl;
}

// 测试展开 S2 命名空间
void testExpandS2Namespace()
{
	std::cout << "开始测试展开 S2 命名空间..." << std::endl;
	using S1::S2::funA;
	S1::S2::x = 30;
	std::cout << "展开 S2 命名空间后访问变量 x: " << S1::S2::x << std::endl;
	funA();
	std::cout << "S2 命名空间展开测试结束。" << std::endl;
	std::cout << std::endl;
}

// C++ 标准库使用命名空间 std
// 方式 1: 指定命名空间，不使用 using namespace std;
void testStdNamespaceMethod1()
{
	std::cout << "开始测试使用标准库命名空间 std 的方式 1（指定命名空间）..." << std::endl;
	std::cout << "使用方式 1: 指定命名空间 输出 hello world" << std::endl;
	std::cout << "hello world" << std::endl;
	std::cout << "标准库命名空间 std 的方式 1 测试结束。" << std::endl;
	std::cout << std::endl;
}

// 方式 2: 把 std 整个展开
void testStdNamespaceMethod2()
{
	std::cout << "开始测试使用标准库命名空间 std 的方式 2（整个展开）..." << std::endl;
	using namespace std;
	cout << "使用方式 2: 展开 std 命名空间 输出 hello world" << endl;
	cout << "hello world" << endl;
	std::cout << "标准库命名空间 std 的方式 2 测试结束。" << std::endl;
	std::cout << std::endl;
}

// 方式 3: 对部分常用的库里的东西展开
void testStdNamespaceMethod3()
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
void testCinCoutFunctionality()
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
void testDefaultParameter()
{
	std::cout << "开始测试缺省参数函数..." << std::endl;
	// 只传入一个参数，使用缺省参数
	int result1 = yzq::addWithDefault(3);
	std::cout << "调用 yzq::addWithDefault(3) ，使用缺省参数，结果为：" << result1 << std::endl;

	// 传入两个参数，不使用缺省参数
	int result2 = yzq::addWithDefault(3, 4);
	std::cout << "调用 yzq::addWithDefault(3, 4) ，不使用缺省参数，结果为：" << result2 << std::endl;

	yzq::defaultFun1(1);

	std::cout << "缺省参数函数测试结束。" << std::endl;
	std::cout << std::endl;
}

namespace yzq1
{
	int add(int a, int b)
	{
		return a + b;
	}
}

namespace yzq2
{
	int add(int a, int b)
	{
		return a + b;
	}

	int add(int a, char b)
	{
		return a + b;
	}
}

void testFunOverLoadingPrinciple()
{
	std::cout << "通过反汇编测试函数重载原理..." << std::endl;
	std::cout << yzq2::add(1, '2') << std::endl;
	std::cout << yzq2::add(1, 2) << std::endl;
}

// 测试引用作为变量别名
void testReferenceAsAlias()
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
void swap(int &r1, int &r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

// 测试引用在交换函数中的基本使用
void testSwapWithReferenceBasic()
{
	std::cout << "--- 测试引用在交换函数中的基本使用 ---" << std::endl;
	int x = 1, y = 2;
	std::cout << "交换前，x: " << x << ", y: " << y << std::endl;

	swap(x, y);
	std::cout << "交换后，x: " << x << ", y: " << y << std::endl;

	assert(x == 2 && y == 1);
	std::cout << "测试通过！" << std::endl;
}

// 测试单链表插入操作的函数
void testSingleListPushBack()
{
	std::cout << "--- 开始测试单链表插入操作 ---" << std::endl;
	// 这里假设 PListNode 是之前定义好的类型
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
void testReferenceInitialization()
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

// 定义一个结构体，包含一个大数组
struct A
{
	int aArray[100000];
};

// 性能测试类
class performanceTester
{
private:
	// 以值作为函数参数
	void testFunc1(A a) {}

	// 以引用作为函数参数
	void testFunc2(A &aa) {}

	// 传地址
	void testFunc3(A *paa) {}

public:
	// 测试值传递、引用传递和指针传递的性能
	void testRefAndValue()
	{
		A a;
		std::cout << "开始进行性能测试..." << std::endl;

		// 以值作为函数参数
		clock_t begin1 = clock();
		if (begin1 == -1)
		{
			std::cerr << "获取开始时间失败（值传递）" << std::endl;
			return;
		}
		std::cout << "开始值传递测试..." << std::endl;
		for (size_t i = 0; i < 100000; ++i)
			testFunc1(a);
		clock_t end1 = clock();
		if (end1 == -1)
		{
			std::cerr << "获取结束时间失败（值传递）" << std::endl;
			return;
		}
		std::cout << "值传递测试结束。" << std::endl;

		// 以引用作为函数参数
		clock_t begin2 = clock();
		if (begin2 == -1)
		{
			std::cerr << "获取开始时间失败（引用传递）" << std::endl;
			return;
		}
		std::cout << "开始引用传递测试..." << std::endl;
		for (size_t i = 0; i < 100000; ++i)
			testFunc2(a);
		clock_t end2 = clock();
		if (end2 == -1)
		{
			std::cerr << "获取结束时间失败（引用传递）" << std::endl;
			return;
		}
		std::cout << "引用传递测试结束。" << std::endl;

		// 传地址
		clock_t begin3 = clock();
		if (begin3 == -1)
		{
			std::cerr << "获取开始时间失败（指针传递）" << std::endl;
			return;
		}
		std::cout << "开始指针传递测试..." << std::endl;
		for (size_t i = 0; i < 100000; ++i)
			testFunc3(&a);
		clock_t end3 = clock();
		if (end3 == -1)
		{
			std::cerr << "获取结束时间失败（指针传递）" << std::endl;
			return;
		}
		std::cout << "指针传递测试结束。" << std::endl;

		// 分别计算函数运行结束后的时间
		double time1 = static_cast<double>(end1 - begin1) / CLOCKS_PER_SEC * 1000;
		double time2 = static_cast<double>(end2 - begin2) / CLOCKS_PER_SEC * 1000;
		double time3 = static_cast<double>(end3 - begin3) / CLOCKS_PER_SEC * 1000;

		std::cout << "testFunc1(a) - 时间（毫秒）: " << time1 << std::endl;
		std::cout << "testFunc2(a&) - 时间（毫秒）: " << time2 << std::endl;
		std::cout << "testFunc3(a*) - 时间（毫秒）: " << time3 << std::endl;
	}
};

// 函数 Count，返回一个整数值
int count()
{
	int n = 0;
	n++;
	// ...
	std::cout << "Count 函数返回值: " << n << std::endl;
	return n;
}

// 测试函数
void testReturnValueAndReference()
{
	std::cout << "--- 开始测试函数返回值与引用 ---" << std::endl;

	// 正常接收返回值
	int ret = count();
	std::cout << "使用普通变量接收返回值: ret = " << ret << std::endl;

	// 尝试使用非常量引用接收返回值（会导致编译错误，这里注释掉）
	// int& ret2 = count();

	// 使用常量引用接收返回值
	const int &ret3 = count();
	std::cout << "使用常量引用接收返回值: ret3 = " << ret3 << std::endl;

	std::cout << "--- 测试结束 ---" << std::endl;
}

// 定义 Count 函数，使用静态局部变量
int countStatic()
{
	static int n = 0; // 静态变量只会初始化一次。
	n++;
	// ...
	return n;
}

// 测试函数
void testStaticVariableInFunction()
{
	std::cout << "--- 开始测试静态局部变量在函数中的特性 ---" << std::endl;
	std::cout << "第一次调用 Count 函数的返回值: " << countStatic() << std::endl;
	std::cout << "第二次调用 Count 函数的返回值: " << countStatic() << std::endl;
	std::cout << "第三次调用 Count 函数的返回值: " << countStatic() << std::endl;
	std::cout << "--- 测试结束 ---" << std::endl;
}

#if 0
// 返回局部变量引用的函数
// int &countReturnReference()
int &countReturnReference()
{
	int countReturnReferenceN = 0;
	countReturnReferenceN++;

	// 输出局部变量 n 的地址
	std::cout << "&n: " << &countReturnReferenceN << std::endl;

	// ...
	return countReturnReferenceN;
}

// 测试函数
void testReturnReference()
{
	std::cout << "--- 开始测试返回局部变量引用的函数 ---" << std::endl;

	int &ret1 = countReturnReference();

	// 输出引用 ret 的地址
	std::cout << "ret: " << &ret1 << std::endl;

	std::cout << "ret 的值: " << ret1 << std::endl;
	std::cout << "ret 的值: " << ret1 << std::endl;
	std::cout << "ret 的值: " << ret1 << std::endl;

	std::cout << "--- 测试结束 ---" << std::endl;
}

#endif

// 定义全局变量 a
A a;

// 值返回函数
A testFunc1()
{
	return a;
}

// 引用返回函数
A &testFunc2()
{
	return a;
}

// 测试引用返回和值返回效率
void testReturnByRefOrValue()
{
	std::cout << "--- 开始测试值返回和引用返回的性能 ---" << std::endl;

	// 以值作为函数的返回值类型
	clock_t begin1 = clock();
	std::cout << "开始执行值返回函数测试..." << std::endl;
	for (size_t i = 0; i < 100000; ++i)
		testFunc1();
	clock_t end1 = clock();
	std::cout << "值返回函数测试结束。" << std::endl;

	// 以引用作为函数的返回值类型
	clock_t begin2 = clock();
	std::cout << "开始执行引用返回函数测试..." << std::endl;
	for (size_t i = 0; i < 100000; ++i)
		testFunc2();
	clock_t end2 = clock();
	std::cout << "引用返回函数测试结束。" << std::endl;

	// 计算两个函数运算完成之后的时间
	std::cout << "testFunc1 执行时间: " << static_cast<double>(end1 - begin1) / CLOCKS_PER_SEC * 1000 << " 毫秒" << std::endl;
	std::cout << "testFunc2 执行时间: " << static_cast<double>(end2 - begin2) / CLOCKS_PER_SEC * 1000 << " 毫秒" << std::endl;

	std::cout << "--- 测试结束 ---" << std::endl;
}

// 测试常量引用作为函数参数
void printValue(const int &value)
{
	std::cout << "常量引用的值: " << value << std::endl;
	// 下面代码若取消注释会导致编译错误，因为常量引用不能修改
	// value = 30;
}

void testConstReferenceAsFunctionParameter()
{
	std::cout << "--- 测试常量引用作为函数参数 ---" << std::endl;
	int num = 10;
	const int constNum = 20;

	printValue(num);
	printValue(constNum);
	std::cout << "测试通过！（注意：尝试修改常量引用会导致编译错误）" << std::endl;
}

// 此函数用于测试引用的权限问题，包括权限放大、权限不变和权限缩小的情况
void testReferencePermission()
{
	std::cout << "开始进行引用权限测试..." << std::endl;

	// 定义一个常量整数 a
	const int a = 10;
	std::cout << "已定义常量 a = " << a << std::endl;

	// 以下语句若取消注释会编译错误，因为将常量 a 赋值给非常量引用属于权限放大
	// int& ra = a;

	// a被const修饰，表示a是只读的，如果 int& ra = a; 就变成可读可写的了。

	// 定义一个常量引用 ra 引用 a，这是权限不变的操作
	const int &ra = a;
	std::cout << "已定义常量引用 ra 引用 a，ra = " << ra << std::endl;

	// 赋值操作，将 a 的值拷贝给 b，此操作不受权限放大的影响
	int b = a;
	std::cout << "已将 a 的值拷贝给 b，b = " << b << std::endl;

	// 定义一个整数 c
	int c = 10;
	std::cout << "已定义变量 c = " << c << std::endl;

	// 定义一个引用 rb 引用 c，这是权限不变的操作
	int &rb = c;
	std::cout << "已定义引用 rb 引用 c，rb = " << rb << std::endl;

	// 定义一个常量引用 crb 引用 c，这是权限缩小的操作，使原本可读可写的 c 变为只读
	const int &crb = c;
	std::cout << "已定义常量引用 crb 引用 c，crb = " << crb << std::endl;

	// 输出 a 和 ra 的值
	std::cout << "a: " << a << ", ra: " << ra << std::endl;

	// 输出 c、rb 和 crb 的值
	std::cout << "c: " << c << ", rb: " << rb << ", crb: " << crb << std::endl;

	std::cout << "引用权限测试结束。" << std::endl;
}

// 测试引用和指针的区别
void testReferenceVsPointer()
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

// 测试引用数组
void testReferenceArray()
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

// 测试引用在类中的使用
class myClass
{
public:
	myClass(int &value) : ref(value) {}
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

void testReferenceInClass()
{
	std::cout << "--- 测试引用在类中的使用 ---" << std::endl;
	int num = 10;
	myClass obj(num);
	obj.printRefValue();

	obj.modifyRefValue(20);
	std::cout << "通过类方法修改引用后，原变量 num 的值: " << num << std::endl;
	assert(num == 20);
	std::cout << "测试通过！" << std::endl;
}

// C++ 推荐频繁调用的小函数 定义成inline，没有栈帧开销。
inline int addInline(int x, int y)
{
	return x + y;
}

// 内联函数测试函数
void testInlineAdd()
{
	int a = 1;
	int b = 2;
	int result = addInline(a, b);
	std::cout << "调用内联函数 Add(" << a << ", " << b << ") 的结果是: " << result << std::endl;
	assert(result == a + b);
	std::cout << "内联函数测试通过！" << std::endl;
}

// auto类型推导测试函数
void testAutoTypeDeduction()
{
	int x = 10;
	auto a = &x;  // int*
	auto *b = &x; // int*  强制指定了b是一个指针
	// auto* b = x; // err 必须给b赋值地址
	int &y = x;	 // y的类型是int
	auto c = y;	 // 推出来的c是int
	auto &d = x; // d的类型是int 但这里强制指定了d是x的引用

	// 打印变量类型 返回的是类型的字符串
	std::cout << "x 的类型: " << typeid(x).name() << std::endl; // int
	std::cout << "y 的类型: " << typeid(y).name() << std::endl; // int
	std::cout << "a 的类型: " << typeid(a).name() << std::endl; // int*
	std::cout << "b 的类型: " << typeid(b).name() << std::endl; // int*
	std::cout << "c 的类型: " << typeid(c).name() << std::endl; // int
	std::cout << "d 的类型: " << typeid(d).name() << std::endl; // int

	std::vector<std::string> v;
	// 传统方式声明迭代器
	std::vector<std::string>::iterator it1 = v.begin();
	std::cout << "传统方式声明的迭代器it1类型: " << typeid(it1).name() << std::endl;
	// 使用auto声明迭代器
	auto it2 = v.begin();
	std::cout << "使用auto声明的迭代器it2类型: " << typeid(it2).name() << std::endl;
}

// 范围for循环测试函数
void testRangeForLoop()
{
	int array[] = {1, 2, 3, 4, 5};
	std::cout << "初始数组元素: ";
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "使用传统for循环将数组元素乘以2后: ";
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		array[i] *= 2;
	}
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "使用范围for循环（引用方式）再次将数组元素乘以2后: ";
	for (auto &e : array)
	{
		e *= 2;
	}
	for (auto e : array)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
// 重载函数定义
void Fun(int p)
{
	std::cout << "Fun(int)" << std::endl;
}

void Fun(int *p)
{
	std::cout << "Fun(int*)" << std::endl;
}
void testFunctionOverloadingWithNull()
{
	// 定义重载函数
	void Fun(int p);
	void Fun(int *p);

	std::cout << "调用 Fun(0) 的结果: ";
	Fun(0);
	std::cout << "调用 Fun(NULL) 的结果: ";
	// Fun(NULL);
	Fun(nullptr);
	std::cout << "调用 Fun((int*)NULL) 的结果: ";
	Fun((int *)NULL);
}

int main(int argc, char const *argv[])
{
	// 测试自定义命名空间 yzq
	// testNamespaceUsage();

	// 测试展开 S2 命名空间
	// testExpandS2Namespace();

	// 测试使用标准库命名空间 std 的三种方式
	// testStdNamespaceMethod1();

	// testStdNamespaceMethod2();

	// testStdNamespaceMethod3();

	// 测试 cin 和 cout 的功能
	// testCinCoutFunctionality();

	// 测试缺省参数的函数
	// testDefaultParameter();

	// 测试函数重载
	// testFunctionOverloading();

	// 测试函数重载原理
	// testFunOverLoadingPrinciple();

	// testReferenceAsAlias();

	// testSwapWithReferenceBasic();

	// testSingleListPushBack();

	// testConstReferenceAsFunctionParameter();

	// performanceTester().testRefAndValue();

	// testReturnValueAndReference();

	// testStaticVariableInFunction();

	// testReturnReference();

	// testReturnByRefOrValue();

	// testReferencePermission();

	// testInlineAdd();

	// testAutoTypeDeduction();

	// testRangeForLoop();

	testFunctionOverloadingWithNull();

	return 0;
}