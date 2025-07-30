/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-06-09 19:39:12
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <time.h>
#include <stack>
#include <queue>
#include <memory>
#include <cstddef>
#include <cstdio>
#include <cstdint>

#if 0
class Person
{
public:
	void Print()
	{
		std::cout << "name:" << _name << std::endl;
		std::cout << "age:" << _age << std::endl;
	}
	// protected/private成员对于基类 -- 一样的，类外面不能访问，类里面可以访问
	// protected/private成员对于派生类 -- private成员不能用 protected成员类里面可以用

	// protected:
private:
	std::string _name = "peter"; // 姓名
	int _age = 18;				 // 年龄
								 // ...
};

// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
class Student : public Person
{
public:
	void func()
	{
		Print();
		//_age = 0; // 不可见
	}

protected:
	int _stuid; // 学号
};

class Teacher : public Person
{
protected:
	int _jobid; // 工号
};

void test1()
{
	Student s;
	std::cout << sizeof(s) << std::endl;

	Teacher t;
	// s._age = 0;
	s.Print();
	t.Print();
}

#endif

#if 0
class Person
{

	// protected:
public:
	std::string _name;
	std::string _sex;
	int _age;
};

// 必须建立在公有继承的基础上
class Student : public Person
{
public:
	int _No; // 学号
};

void test2()
{
	Person p;
	Student s;
	s._name = "张三";
	s._age = 18;
	s._sex = "男";

	// 子类对象给父类 对象/指针/引用 -- 语法天然支持，没有类型转换，也就不存在临时对象
	p = s;							  // 对象赋值 - 只复制父类部分
	Person &rp = s;					  // 引用绑定 - 指向子类对象的父类部分
	Person *ptrp = &s;				  // 指针赋值 - 指向子类对象的父类部分
	std::cout << s._age << std::endl; // 18
	std::cout << p._age << std::endl; // 18

	// 指向都是同一块空间。指向的都是同一个地址，不过解引用得到的是不同的。rp ptrp只有子类中父类的成员
	std::cout << &s << std::endl;	// 012FFAA0
	std::cout << &rp << std::endl;	// 012FFAA0
	std::cout << ptrp << std::endl; // 012FFAA0
	rp._age++;
	ptrp->_age++;
	std::cout << s._age << std::endl; // 20
	std::cout << p._age << std::endl; // 18 没有影响p中的成员

	// 基类不能赋值给子类，即使强转也不行
	// s = (Student)p;

	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	ptrp = &s;
	Student *ps1 = (Student *)ptrp; // 安全转换 - ptrp原本指向Student
	ps1->_No = 10;					// 正常访问

	ptrp = &p;
	Student *ps2 = (Student *)ptrp; // 危险转换 - ptrp指向纯Person对象
	ps2->_No = 10;					// 越界访问 - 修改了Person对象之后的内存
}
#endif

#if 0
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
class Person
{
protected:
	std::string _name = "小李子"; // 姓名
	int _num = 111;				  // 身份证号
};

class Student : public Person
{
public:
	void Print()
	{
		std::cout << " 姓名:" << _name << std::endl;
		// 屏蔽了父类的同名成员变量
		std::cout << " 学号:" << _num << std::endl; // 999
		// 利用类域访问
		std::cout << " 身份证号:" << Person::_num << std::endl; // 111
	}

protected:
	int _num = 999; // 学号
};

void test3()
{
	Student s;
	s.Print();
}
#endif

#if 0

// 这2个fun关系仍然是隐藏
// 这里不是重载，函数重载要求在同一个作用域
class A
{
public:
	void fun()
	{
		std::cout << "A::func()" << std::endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		std::cout << "B : public A" << std::endl;
	}
};

void test4()
{
	B b;
	// b.fun();// 报错 默认调用自己的，需要传参
	//  调用子类自己的
	b.fun(1);	// B : public A
	b.A::fun(); // A::func() 指定作用域才能调用父类的
};

#endif

#if 0

class Person
{
public:
	Person(const char *name = "Peter")
		: _name(name)
	{
		std::cout << "Person()" << std::endl;
	}

	Person(const Person &p)
		: _name(p._name)
	{
		std::cout << "Person(const Person& p)" << std::endl;
	}

	Person &operator=(const Person &p)
	{
		std::cout << "Person operator=(const Person& p)" << std::endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		std::cout << "~Person()" << std::endl;
	}

protected:
	std::string _name; // 姓名
};

class Student : public Person
{
public:
	Student(const char *name = "", int num = 0)
		: Person(name), _num(num)
	{
		std::cout << "Student(const char* name = , int num = 0)" << std::endl;
	}

	Student(const Student &s)
		// 调用父类拷贝构造，需要传父类对象，利用切割！
		: Person(s), // 切割，子类的对象可以传给父类的引用
		  _num(s._num)
	{
	}
	Student &operator=(const Student &s)
	{
		if (this != &s)
		{
			// operator=(s); // 同样是切割，子类对象传给父类引用
			Person::operator=(s); // 指定作用域，调用父类的operator=
			_num = s._num;
		}
		return *this;
	}

	// 父子类的析构函数存在隐藏关系，虽然他们看上去名称不同
	// 由于的多态的需要，析构函数名被统一处理成destructor()
	// 因此构成了隐藏关系
	~Student()
	{
		// 子类析构完成之后会自动调用父类的析构 不显示调用才是对的
		// Person::~Person();
		std::cout << "~Student()" << std::endl;
	}

protected:
	int _num; // 学号
};

void test5()
{
	Student s1("李四", 1);
	// Student s2(s1);
	// Student s3("王五", 2);
	// s1 = s3;
}
#endif

#if 0

class Student; // 必须前置声明Student
class Person
{
public:
	friend void Display(const Person &p, const Student &s);

protected:
	std::string _name = "Peter"; // 姓名
};
class Student : public Person
{
public:
	// friend void Display(const Person& p, const Student& s); // 必须在父类子类都声明友元才行
protected:
	int _stuNum; // 学号
};

// Display是父类的友元，但不是子类的友元。友元关系不能继承下来，因此不能访问子类的成员
void Display(const Person &p, const Student &s)
{
	// Display 是 Person 的友元，可以直接访问 Person 的成员
	// s._name 的本质是 Person 的成员
	std::cout << p._name << std::endl;
	std::cout << s._name << std::endl;
	// std::cout << s._stuNum << std::endl; // err 成员 "Student::_stuNum" (已声明 所在行数:295) 不可访问
}

void test6()
{
	Person p;
	Student s;
	Display(p, s);
}

#endif

#if 0

class Base
{
public:
	static int s_value; // 静态成员变量
	static void Print()
	{ // 静态成员函数
		std::cout << "Base::s_value = " << s_value << std::endl;
	}
};

int Base::s_value = 10; // 初始化静态变量

class Derived : public Base
{
public:
	static int s_value; // 静态成员变量
	static void Print()
	{ // 静态成员函数
		std::cout << "Derived::s_value = " << s_value << std::endl;
	}
}; // 派生类
int Derived::s_value = 200; // 初始化静态变量

void test7()
{
	// 通过基类访问静态成员
	Base::Print();		// 输出：Base::s_value = 10
	Base::s_value = 20; // 修改静态变量

	// 通过派生类访问静态成员
	Derived::Print();													 // 输出：Base::s_value = 20
	std::cout << "Derived::s_value = " << Derived::s_value << std::endl; // 输出：20
}

#endif

#if 0

class Person
{
public:
	std::string _name; // 姓名
	int _a[10000];
};
class Student : public Person
{
protected:
	int _num; // 学号
};
class Teacher : public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	std::string _majorCourse; // 主修课程
};

void test8()
{
	Assistant a;
	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";

	std::cout << sizeof(a) << std::endl; // 80088
}
#endif

#if 0

class Person
{
public:
	std::string _name; // 姓名
	int _a[10000];
};
class Student : virtual public Person
{
protected:
	int _num; // 学号
};
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	std::string _majorCourse; // 主修课程
};

void test8()
{
	Assistant a;
	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";

	std::cout << sizeof(a) << std::endl; // 40080
}
#endif

#if 0

class Base1
{
public:
	int _b1;
};

class Base2
{
public:
	int _b2;
};

class Derive : public Base1, public Base2
{
public:
	int _d;
};

int main()
{
	Derive d;
	Base1 *p1 = &d;
	Base2 *p2 = &d;
	Derive *p3 = &d;
	// 输出各自地址
	std::cout << p1 << std::endl; // 0x16bc05b70
	std::cout << p2 << std::endl; // 0x16bc05b74
	std::cout << p3 << std::endl; // 0x16bc05b70
	return 0;
}

#endif

#if 0

// 基类A
class A
{
public:
	virtual void funcA()
	{ // 虚函数支持多态
		std::cout << "A::funcA() [_a=" << _a << "]" << std::endl;
	}

	void protectedCall()
	{ // 演示protected成员访问
		std::cout << "A::protectedCall() [_a=" << _a << "]" << std::endl;
	}

protected:
	int _a = 0;
};

// 继承方式（白盒复用）
class B : public A
{
public:
	void funcB()
	{
		std::cout << "B::funcB():" << std::endl;
		A::funcA(); // 直接调用基类方法
		_a++;		// 直接访问基类protected成员
		A::funcA(); // 展示状态变更
	}

	// 重写虚函数
	void funcA() override
	{
		std::cout << "B::overrideFuncA() [_a=" << _a << "]" << std::endl;
	}
};

// 组合接口（定义组件需实现的功能）
class IComponent
{
public:
	// 纯虚函数，确保子类实现 包含纯虚函数的类称为抽象类，不能直接实例化。
	virtual void doSomething() = 0;
	// 确保通过基类指针删除子类对象时，子类析构函数被正确调用。
	virtual ~IComponent() = default;
};

// 具体组件实现
class ComponentA : public IComponent
{
public:
	void doSomething() override
	{
		std::cout << "ComponentA::doSomething()" << std::endl;
	}
};

class ComponentB : public IComponent
{
public:
	void doSomething() override
	{
		std::cout << "ComponentB::doSomething()" << std::endl;
	}
};

// 组合方式（黑盒复用）
class D
{
private:
	A _aObj; // 组合A对象
	// unique_ptr C++11 引入的智能指针，用于管理动态分配的对象，确保内存自动释放
	// 同一时间只能有一个 unique_ptr 指向该对象，无法复制，但可以移动
	std::unique_ptr<IComponent> _component; // 动态组件

public:
	// 构造函数初始化默认组件
	D() : _component(std::make_unique<ComponentA>()) {}

	// 通过组合调用A的功能
	void useA()
	{
		std::cout << "D::useA():" << std::endl;
		_aObj.funcA(); // 委托调用
					   // _aObj._a++;	   // 错误：无法访问A的protected成员
	}

	// 运行时替换组件
	// D 类通过组合 IComponent 接口，在运行时动态切换具体实现（如 ComponentA 或 ComponentB）。
	void setComponent(std::unique_ptr<IComponent> component)
	{
		// unique_ptr 禁止拷贝赋值，只能通过移动转移所有权。
		_component = std::move(component);
	}

	void performAction()
	{
		std::cout << "D::performAction():" << std::endl;
		_component->doSomething(); // 运行时行为
	}
};

// 演示函数
void testInheritance()
{
	std::cout << "=== 继承演示 ===" << std::endl;
	B b;
	b.funcB(); // 调用派生类扩展功能

	A *aPtr = &b;  // 多态指针
	aPtr->funcA(); // 动态绑定到B::overrideFuncA()
}

void testComposition()
{
	std::cout << "\n=== 组合演示 ===" << std::endl;
	D d;
	d.useA(); // 通过组合复用A的功能

	d.performAction();								// 使用默认组件
	d.setComponent(std::make_unique<ComponentB>()); // 动态替换组件
	d.performAction();								// 使用新组件
}

int main()
{
	testInheritance();
	testComposition();
	return 0;
}

#endif

#if 0

class A
{
public:
	A(const std::string &s) { std::cout << s << std::endl; }
	~A() {}
};

class B : virtual public A
{
public:
	B(const std::string &s1, const std::string &s2)
		: A(s1) { std::cout << s2 << std::endl; }
};

class C : virtual public A
{
public:
	C(const std::string &s1, const std::string &s2)
		: A(s1) { std::cout << s2 << std::endl; }
};

// class D : public B, public C
class D : public C, public B
{
public:
	D(const std::string &s1, const std::string &s2, const std::string &s3, const std::string &s4)
		: B(s1, s2), C(s1, s3), A(s1)
	{
		std::cout << s4 << std::endl;
	}
};

int main()
{
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}

#endif

#if 0

class Animal
{
public:
	virtual void speak()
	{ // 虚函数
		std::cout << "动物发出声音" << std::endl;
	}
};

class Dog : public Animal
{
public:
	void speak() override
	{ // 重写虚函数
		std::cout << "狗叫：汪汪" << std::endl;
	}
};

class Cat : public Animal
{
public:
	void speak() override
	{
		std::cout << "猫叫：喵喵" << std::endl;
	}
};

void makeAnimalSpeak(Animal *animal)
{
	animal->speak(); // 动态绑定，根据实际对象类型调用对应 speak()
}

int main()
{
	Animal animal;
	Dog dog;
	Cat cat;

	makeAnimalSpeak(&animal); // 输出：动物发出声音
	makeAnimalSpeak(&dog);	  // 输出：狗叫：汪汪
	makeAnimalSpeak(&cat);	  // 输出：猫叫：喵喵

	return 0;
}

#endif

#if 0

class Person
{
protected:
	std::string _name;
	// int _id;
public:
	Person(const char *name)
		: _name(name)
	{
	}

	// 虚函数
	virtual void BuyTicket() { std::cout << _name << " Person: 买票-全价 100元" << std::endl; };
};

class Student : public Person
{
public:
	Student(const char *name)
		: Person(name)
	{
	}

	// 虚函数 + 函数名/参数/返回值都相同  -》 重写/覆盖
	// 子类重写了父类的虚函数
	virtual void BuyTicket() { std::cout << _name << " Student：买票-半价 50 ￥" << std::endl; }
};

class Soldier : public Person
{
public:
	Soldier(const char *name)
		: Person(name)
	{
	}

	virtual void BuyTicket() { std::cout << _name << " Soldier：优先买预留票-88折 88 ￥" << std::endl; }
};

// 多态2个要求
// 1、子类虚函数重写父类虚函数 （重写要求虚函数 + 函数名/参数/返回值都相同）
// 2、必须是父类指针、引用去调用虚函数

#if 0
void Pay(Person *ptr)
{
	ptr->BuyTicket();
}

int main()
{
	int option = 0;
	std::cout << "================================================" << std::endl;
	do
	{
		std::cout << "请选择身份：";
		std::cout << "1、普通人 2、学生 3、军人" << std::endl;
		std::cin >> option;
		std::cout << "请输入名字：" << std::endl;
		std::string name;
		std::cin >> name;
		switch (option)
		{
		case 1:
			// string需要转化为const char* 类型字符串
			// 不考虑内存泄露，直接new
			// new之后的返回值是一个指针
			Pay(new Person(name.c_str()));
			break;
		case 2:
			Pay(new Student(name.c_str()));
			break;
		case 3:
			Pay(new Soldier(name.c_str()));
			break;
		default:
			std::cout << "输入错误，请重新输入" << std::endl;
			break;
		}
		std::cout << "================================================" << std::endl;
	} while (option != -1);
}
#endif

#if 1

void Pay(Person &ptr)
{
	ptr.BuyTicket();
}

int main()
{
	int option = 0;
	std::cout << "================================================" << std::endl;
	do
	{
		std::cout << "请选择身份：";
		std::cout << "1、普通人 2、学生 3、军人" << std::endl;
		std::cin >> option;
		std::cout << "请输入名字：" << std::endl;
		std::string name;
		std::cin >> name;
		switch (option)
		{
		case 1:
		{
			// case里面不能直接定义对象，需要加域{}
			Person p(name.c_str());
			Pay(p);
			break;
		}
		case 2:
		{
			Student s(name.c_str());
			Pay(s);
			break;
		}

		case 3:
		{
			Soldier s(name.c_str());
			Pay(s);
			break;
		}

		default:
			std::cout << "输入错误，请重新输入" << std::endl;
			break;
		}
		std::cout << "================================================" << std::endl;
	} while (option != -1);
}

#endif

#endif

#if 0

class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); } // this->func() 这里是多态调用
};

class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};

int main(int argc, char *argv[])
{
	B *p = new B;
	p->test(); // 子类指针可以调用父类的成员函数，test是被继承下来的，但是这里的test中this指针还是A*，p去调用时，p传给了this，这时this指针就是B*类型
	// 这里是继承调用
	return 0;
}
// 输出结果？ B->1

#endif

#if 0

class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); } // this->func() 这里是多态调用
};

class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};

int main(int argc, char *argv[])
{
	B *p = new B;
	p->func(); // B->0
	// 这里只是普通调用，不符合多态的条件，p不是父类的指针或引用。

	A *p2 = new B;
	p2->func(); // 这才是多态调用 B->1

	A *p3 = new A;
	p3->func(); // A->1
	A a;
	a.func(); // A->1
	return 0;
}
// 输出结果？ B->0 B->1

#endif

#if 0
class Car
{
public:
	virtual void Drive() {}
};
// override 写在子类中，要求严格检查是否完成重写，没完成会报错。
class Benz : public Car
{
public:
	virtual void Drive() override { std::cout << "Benz-舒适" << std::endl; }
};

int main(int argc, char const *argv[])
{
	Car *pBenz = new Benz;
	pBenz->Drive();
	return 0;
}

#endif

#if 0

class Car
{
public:
	virtual void Drive() = 0;
};

class BMw : public Car
{
public:
	virtual void Drive()
	{
		std::cout << "BMW-操控" << std::endl;
	}
};
class Benz : public Car
{
public:
	virtual void Drive()
	{
		std::cout << "Benz-舒适" << std::endl;
	}
};
void func(Car *p)
{
	p->Drive();
}
int main()
{
	func(new BMw);
	func(new Benz);
	return 0;
}

#endif

#if 0

// sizeof(Base)是多少？
class Base
{
public:
	virtual void Func1()
	{
		std::cout << "Func1()" << std::endl;
	}

public:
	int _b = 1;
};

int main()
{
	Base b;
	std::cout << sizeof(Base) << std::endl; // 8 32位编译器下
	// std::cout << "vptr offset: " << offsetof(Base, _b) << std::endl; // 输出8（Clang）
	return 0;
}

#endif

#if 0
class Base
{
public:
	virtual void Func1()
	{
		std::cout << "Base : virtual void Func1()" << std::endl;
	}
	void Func2()
	{
		std::cout << "Base : void Func2()" << std::endl;
	}
	virtual void Func3()
	{
		std::cout << "Base : virtual void Func3()" << std::endl;
	}

private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		std::cout << "Derive : virtual void Func1()" << std::endl;
	}

private:
	int _d = 2;
};
int main()
{
	Base b;
	std::cout << sizeof(Base) << std::endl; // 8
	Derive d;
	std::cout << sizeof(Derive) << std::endl; // 12

	// prt指向父类对象时，ptr->Func1() 在b的虚表中找到的虚函数是 Base::Func1()
	Base *ptr = &b;
	ptr->Func1();
	ptr->Func2();

	// 当ptr指向子类对象时，ptr->Func1() 在d的虚表中找到的是虚函数是 Derive::Func1()
	ptr = &d;
	ptr->Func1();

	Base *ptr2 = &b;
	ptr2->Func2();
	// Func2() 是普通函数，不是虚函数，所以ptr2->Func2() 调用的是 Base::Func2()
	ptr2 = &d;
	ptr2->Func2();

	Derive d1;
	Derive d2;
	Derive d3;
	return 0;
}

#endif

#if 0

class Base
{
public:
	virtual void func() {}
};

class Derived : public Base
{
public:
	void func() override {}
};

int globalVar = 0;				  // 全局变量（数据段）
const char *constStr = "literal"; // 字符串字面量（代码段）

int main()
{
	// ===== 栈区域 =====
	int stackVar = 0;
	Base stackObj1;
	Base stackObj2;
	Derived derivedObj;

	// ===== 堆区域 =====
	int *heapVar = new int(0);
	Base *heapObj = new Derived();

	// ===== 静态区域 =====
	static int staticVar = 0;

	// ===== 代码段 =====
	void (*funcPtr)() = []() {}; // 函数指针（指向代码段）

	// ===== 读取虚表地址（64位系统，前8字节） =====
	uint64_t vtableAddr1 = *reinterpret_cast<uint64_t *>(&stackObj1);
	uint64_t vtableAddr2 = *reinterpret_cast<uint64_t *>(&stackObj2);
	uint64_t derivedVtableAddr = *reinterpret_cast<uint64_t *>(&derivedObj);
	uint64_t heapVtableAddr = *reinterpret_cast<uint64_t *>(heapObj);

	// ===== 打印各区域地址 =====
	printf("===== 内存区域验证（64位系统） =====\n\n");

	// 栈区域
	printf("[栈区域]\n");
	printf("栈变量地址:        %p\n", &stackVar);
	printf("栈对象1地址:       %p\n", &stackObj1);
	printf("栈对象2地址:       %p\n", &stackObj2);
	printf("派生类对象地址:    %p\n\n", &derivedObj);

	// 堆区域
	printf("[堆区域]\n");
	printf("堆变量地址:        %p\n", heapVar);
	printf("堆对象地址:        %p\n\n", heapObj);

	// 静态区域
	printf("[静态区域]\n");
	printf("全局变量地址:      %p\n", &globalVar);
	printf("静态变量地址:      %p\n\n", &staticVar);

	// 代码段
	printf("[代码段]\n");
	printf("字符串字面量地址:  %p\n", constStr);
	printf("函数指针地址:      %p\n\n", funcPtr);

	// 虚表地址验证
	printf("[虚表地址验证]\n");
	printf("Base类虚表地址1:   %p\n", reinterpret_cast<void *>(vtableAddr1));
	printf("Base类虚表地址2:   %p\n", reinterpret_cast<void *>(vtableAddr2));
	printf("Derived类虚表地址: %p\n", reinterpret_cast<void *>(derivedVtableAddr));
	printf("堆对象虚表地址:    %p\n\n", reinterpret_cast<void *>(heapVtableAddr));

	// 验证虚表共享性
	printf("[验证虚表共享性]\n");
	printf("Base对象是否共享虚表: %s\n", (vtableAddr1 == vtableAddr2) ? "是" : "否");
	printf("栈对象与堆对象虚表是否相同: %s\n",
		   (vtableAddr1 == heapVtableAddr) ? "是（类型相同）" : "否（类型不同）");

	// 释放堆内存
	delete heapVar;
	delete heapObj;
	return 0;
}

#endif

#if 0

// 用于演示的基类
class Base
{
public:
	// 虚函数
	virtual void virtualFunc() { printf("Base::virtualFunc()\n"); }
	// 普通成员函数
	void normalFunc() { printf("Base::normalFunc()\n"); }
};

// 派生类，用于验证多态下虚函数表
class Derived : public Base
{
public:
	// 重写虚函数
	void virtualFunc() override { printf("Derived::virtualFunc()\n"); }
};

// 全局普通函数，用于获取其地址
void globalNormalFunc() { printf("globalNormalFunc()\n"); }

// 全局静态变量，用于验证静态区
static int globalStaticVar = 0;
// 全局变量，用于验证静态区（数据段）
int globalVar = 0;

// 辅助函数：用于调用成员函数指针
template <typename T, typename Ret, typename... Args>
Ret callMemberFunction(T *obj, Ret (T::*func)(Args...), Args... args)
{
	return (obj->*func)(args...);
}

int main()
{
	// 栈上的对象和变量
	int stackVar = 0;
	Base stackBaseObj;
	Derived stackDerivedObj;

	// 堆上的对象
	Base *heapBaseObj = new Base();
	Derived *heapDerivedObj = new Derived();

	// 静态变量（函数内的静态变量，属于静态区）
	static int localStaticVar = 0;

	// 字符串字面量，存储在代码段（只读数据区 ）
	const char *codeSegStr = "hello world in code segment";

	// 获取各类地址
	// 栈相关地址
	uintptr_t stackVarAddr = reinterpret_cast<uintptr_t>(&stackVar);
	uintptr_t stackBaseObjAddr = reinterpret_cast<uintptr_t>(&stackBaseObj);
	uintptr_t stackDerivedObjAddr = reinterpret_cast<uintptr_t>(&stackDerivedObj);

	// 堆相关地址
	uintptr_t heapBaseObjAddr = reinterpret_cast<uintptr_t>(heapBaseObj);
	uintptr_t heapDerivedObjAddr = reinterpret_cast<uintptr_t>(heapDerivedObj);

	// 静态区相关地址
	uintptr_t globalStaticVarAddr = reinterpret_cast<uintptr_t>(&globalStaticVar);
	uintptr_t globalVarAddr = reinterpret_cast<uintptr_t>(&globalVar);
	uintptr_t localStaticVarAddr = reinterpret_cast<uintptr_t>(&localStaticVar);

	// 代码段相关地址（字符串字面量、普通函数 ）
	uintptr_t codeSegStrAddr = reinterpret_cast<uintptr_t>(codeSegStr);
	uintptr_t globalNormalFuncAddr = reinterpret_cast<uintptr_t>(reinterpret_cast<void *>(&globalNormalFunc));

	// 虚表地址（64位系统，对象前8字节是虚表指针，解引用得到虚表地址 ）
	uintptr_t baseVtableAddr = *reinterpret_cast<uintptr_t *>(&stackBaseObj);
	uintptr_t derivedVtableAddr = *reinterpret_cast<uintptr_t *>(&stackDerivedObj);

	// 虚函数地址（通过虚表获取）
	uintptr_t baseVirtualFuncAddr = *reinterpret_cast<uintptr_t *>(baseVtableAddr);
	uintptr_t derivedVirtualFuncAddr = *reinterpret_cast<uintptr_t *>(derivedVtableAddr);

	// 收集所有地址及描述到一个vector中，方便排序和输出
	std::vector<std::pair<uintptr_t, std::string>> addrInfoList = {
		{stackVarAddr, "栈变量(stackVar)"},
		{stackBaseObjAddr, "栈Base对象(stackBaseObj)"},
		{stackDerivedObjAddr, "栈Derived对象(stackDerivedObj)"},
		{heapBaseObjAddr, "堆Base对象(heapBaseObj)"},
		{heapDerivedObjAddr, "堆Derived对象(heapDerivedObj)"},
		{globalStaticVarAddr, "全局静态变量(globalStaticVar)"},
		{globalVarAddr, "全局变量(globalVar)"},
		{localStaticVarAddr, "函数内静态变量(localStaticVar)"},
		{codeSegStrAddr, "代码段字符串(codeSegStr)"},
		{globalNormalFuncAddr, "全局普通函数(globalNormalFunc)"},
		{baseVtableAddr, "Base类虚表地址"},
		{derivedVtableAddr, "Derived类虚表地址"},
		{baseVirtualFuncAddr, "Base类虚函数地址"},
		{derivedVirtualFuncAddr, "Derived类虚函数地址"}};

	// 输出无法直接转换的成员函数指针信息
	printf("===== 成员函数指针信息 =====\n");
	void (Base::*baseNormalFuncPtr)() = &Base::normalFunc;
	void (Base::*baseVirtualFuncPtr)() = &Base::virtualFunc;
	void (Derived::*derivedVirtualFuncPtr)() = &Derived::virtualFunc;

	printf("Base::normalFunc 指针值: 无法直接转换为整数\n");
	printf("Base::virtualFunc 指针值: 无法直接转换为整数\n");
	printf("Derived::virtualFunc 指针值: 无法直接转换为整数\n");

	// 演示如何通过成员函数指针调用函数
	printf("\n===== 通过成员函数指针调用函数 =====\n");
	callMemberFunction(&stackBaseObj, baseNormalFuncPtr);
	callMemberFunction(&stackBaseObj, baseVirtualFuncPtr);
	callMemberFunction(&stackDerivedObj, derivedVirtualFuncPtr);

	// 按照地址从小到大排序
	std::sort(addrInfoList.begin(), addrInfoList.end(),
			  [](const std::pair<uintptr_t, std::string> &a,
				 const std::pair<uintptr_t, std::string> &b)
			  {
				  return a.first < b.first;
			  });

	// 输出排序后的地址及描述
	printf("\n===== 各类地址排序（从小到大） =====\n");
	for (const auto &item : addrInfoList)
	{
		printf("%-40s: 0x%016lx\n", item.second.c_str(), item.first);
	}

	// 释放堆内存，避免内存泄漏
	delete heapBaseObj;
	delete heapDerivedObj;

	return 0;
}
#endif

#if 0

class Base
{
public:
	virtual void Func1()
	{
		std::cout << "Base ：virtual void Func1()" << std::endl;
	}
	void Func2()
	{
		std::cout << "Base ：void Func2()" << std::endl;
	}
	virtual void Func3()
	{
		std::cout << "Base ：virtual void Func3()" << std::endl;
	}

private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		std::cout << "Derive ：virtual void Func1()" << std::endl;
	}
	virtual void Func4()
	{
		std::cout << "Derive ：virtual void Func4()" << std::endl;
	}

private:
	int _d = 2;
};

class DDerive : public Derive
{
public:
	virtual void Func1()
	{
		std::cout << "DDerive ：virtual void Func1()" << std::endl;
	}
	virtual void Func2()
	{
		std::cout << "DDerive ：virtual void Func2()" << std::endl;
	}
	virtual void Func3()
	{
		std::cout << "DDerive ：virtual void Func3()" << std::endl;
	}
	virtual void Func5()
	{
		std::cout << "DDerive ：virtual void Func5()" << std::endl;
	}
};

// 想办法打印虚表，取内存值，打印并调用，确认是否存在Func4
// 虚表指针指向的是个指针数组，而且全都是函数指针
// 我们自己定义的Func函数都是无参，返回值void的函数
typedef void (*V_FUNC)();
// 等价于 typedef void(*)() V_FUNC; 必须把typedef的名字放在中间

// virtual function table
// void PrintVFTable(V_FUNC a[])
void PrintVFTable(V_FUNC *a, size_t virtualFunSize) // 这其实就是函数指针数组
{
	printf("vfptr:%p\n", a);
	// VS下虚表指针最后是有一个nullptr的 或者清楚有几个虚函数也行
	for (size_t i = 0; i < virtualFunSize; ++i)
	// for (size_t i = 0; a[i] != nullptr; ++i) // vs的虚表最后都是nullptr
	{
		printf("[%zu]:%p->", i, a[i]);
		// 有了函数地址就可以调用函数
		V_FUNC f = a[i];
		f();
	}
}

// 根据平台和架构选择指针类型
#ifdef _WIN64
using VPTR = uint64_t; // 64位Windows
#elif defined(__x86_64__) || (defined(__APPLE__) && defined(__LP64__))
using VPTR = uint64_t; // 64位macOS/Linux（x86_64架构）
#else
using VPTR = uint32_t; // 32位平台
#endif

int main()
{
	Base b;
	Derive d;
	DDerive dd;
	// 取前四个字节就是虚表指针
	// PrintVFTable((*(int*)&d)); // 这样解引用后是一个int不符合，还需再转一次
	// 指针是可以相互转换的，d没法直接转换成V_FUNC*
	std::cout << "b的虚表:" << std::endl;
	PrintVFTable((V_FUNC *)(*((VPTR *)&b)), 2);
	std::cout << std::endl;

	std::cout << "d的虚表:" << std::endl;
	PrintVFTable((V_FUNC *)(*((VPTR *)&d)), 3);
	std::cout << std::endl;

	std::cout << "dd的虚表:" << std::endl;
	PrintVFTable((V_FUNC *)(*((VPTR *)&dd)), 5);
	std::cout << std::endl;

	V_FUNC f1 = ((V_FUNC)(*(VPTR *)(*((VPTR *)&d))));
	f1(); // 等价于 d.Func1()

	// 1. 获取虚表地址
	VPTR vtable_addr = *((VPTR *)&d);

	// 2. 获取虚表中第一个函数的地址
	V_FUNC f2 = (V_FUNC)(*(VPTR *)vtable_addr);

	// 3. 调用函数
	f2(); // 等价于 d.Func1()
	return 0;
}
#endif

#if 0

class Base1
{
public:
	virtual void func1() { std::cout << "Base1::func1" << std::endl; }
	virtual void func2() { std::cout << "Base1::func2" << std::endl; }

private:
	int b1;
};

class Base2
{
public:
	virtual void func1() { std::cout << "Base2::func1" << std::endl; }
	virtual void func2() { std::cout << "Base2::func2" << std::endl; }

private:
	int b2;
};

class Derive : public Base1, public Base2
{
public:
	virtual void func1() { std::cout << "Derive::func1" << std::endl; }
	virtual void func3() { std::cout << "Derive::func3" << std::endl; }

private:
	int d1;
};

typedef void (*VFPTR)();
void PrintVTable(VFPTR vTable[], size_t virtualFunSize)
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	std::cout << " 虚表地址>" << vTable << std::endl;
	for (size_t i = 0; i < virtualFunSize; ++i)
	{
		printf(" 第%zu个虚函数地址 :%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	std::cout << std::endl;
}

int main()
{
	// printf("%p\n", &Derive::func1);

	Derive d;
	PrintVTable((VFPTR *)(*(uint64_t *)&d), 3);
	// 取出d的地址后，类型是Derive* +1跳过的是sizeof(Derive)
	// 不能这么写(&d+sizeof(Base1))  先转成char* 再加位置，再转VFPTR*
	PrintVTable((VFPTR *)(*(uint64_t *)((char *)&d + sizeof(Base1))), 2); // 跳过b1对象指向Base2

	// 这样更方便
	Base2 *ptr = &d;
	PrintVTable((VFPTR *)(*(uint64_t *)ptr), 2);
	return 0;
}

#endif

#if 0

class A
{
public:
	virtual void func1()
	{
		std::cout << "A::func1()" << std::endl;
	}
	int _a;
};

class B : public A
{
public:
	virtual void func1()
	{
		std::cout << "B::func1()" << std::endl;
	}
	int _b;
};

class C : public A
{

public:
	virtual void func1()
	{
		std::cout << "C::func1()" << std::endl;
	}
	int _c;
};

class D : public B, public C
{
public:
	virtual void func1()
	{
		std::cout << "D::func1()" << std::endl;
	}
	virtual void func2()
	{
		std::cout << "D::func2()" << std::endl;
	}
	int _d;
};

typedef void (*VFPTR)();
void PrintVTable(VFPTR vTable[], size_t virtualFunSize)
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	std::cout << " 虚表地址>" << vTable << std::endl;
	for (size_t i = 0; i < virtualFunSize; ++i)
	{
		printf(" 第%zu个虚函数地址 :%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	A a;
	B b;
	C c;
	D d;
	// 多态调用
	B *ptr = &d;
	ptr->func1();
	ptr = &b;
	ptr->func1();
	std::cout << std::endl;

	// 打印D对象的大小和地址
	std::cout << "sizeof(D) = " << sizeof(D) << std::endl;
	std::cout << "&d       = " << &d << std::endl;
	std::cout << std::endl;

	// 打印B子对象的虚表
	std::cout << "B的虚表:" << std::endl;
	PrintVTable((VFPTR *)(*(uint64_t *)&d), 2);

	// 打印C子对象的虚表（通过偏移获取C的vptr）
	std::cout << "C的虚表:" << std::endl;
	PrintVTable((VFPTR *)(*(uint64_t *)((char *)&d + sizeof(B))), 1);

	return 0;
}

#endif

#if 1

class A
{
public:
	virtual void func1()
	{
		std::cout << "A::func1()" << std::endl;
	}
	int _a;
};

class B : virtual public A
{
public:
	virtual void func1()
	{
		std::cout << "B::func1()" << std::endl;
	}
	virtual void func2()
	{
		std::cout << "B::func2()" << std::endl;
	}
	int _b;
};

class C : virtual public A
{

public:
	virtual void func1()
	{
		std::cout << "C::func1()" << std::endl;
	}
	virtual void func2()
	{
		std::cout << "C::func2()" << std::endl;
	}
	int _c;
};

class D : public B, public C
{
public:
	virtual void func1()
	{
		std::cout << "D::func1()" << std::endl;
	}
	virtual void func2()
	{
		std::cout << "D::func2()" << std::endl;
	}
	int _d;
};

typedef void (*VFPTR)();
void PrintVTable(VFPTR vTable[], size_t virtualFunSize)
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	std::cout << " 虚表地址>" << vTable << std::endl;
	for (size_t i = 0; i < virtualFunSize; ++i)
	{
		printf(" 第%zu个虚函数地址 :%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}

#endif