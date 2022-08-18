#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//
//	//protected:
//public:
//	string _name;
//	string _sex;
//	int	_age;
//};
//
//// 必须建立在公有继承的基础上
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	s._name = "张三";
//	s._age = 18;
//	s._sex = "男";
//
//	// 子类对象给父类 对象/指针/引用 -- 语法天然支持，没有类型转换，也就不存在临时对象
//	p = s;
//	Person& rp = s;
//	Person* ptrp = &s;
//	cout << s._age << endl; // 18
//	cout << p._age << endl; // 18
//
//	// 指向都是同一块空间
//	cout << &s << endl; // 012FFAA0
//	cout << &rp << endl; // 012FFAA0
//	cout << ptrp << endl; // 012FFAA0
//	rp._age++;
//	ptrp->_age++;
//	cout << s._age << endl; // 20
//	cout << p._age << endl; // 18
//
//	// 基类不能赋值给之类，即使强转也不行
//	//s = (Student)p;
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	ptrp = &s;
//	Student* ps1 = (Student*)ptrp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//
//	ptrp = &p;
//	Student* ps2 = (Student*)ptrp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//	return 0;
//}


// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		// 屏蔽了父类的同名成员变量
//		cout << " 学号:" << _num << endl; // 999
//		// 利用类域访问
//		cout << " 身份证号:" << Person::_num << endl; // 111
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//	return 0;
//}

// 这2个fun关系仍然是隐藏
// 这里不是重载，函数重载要求在同一个作用域
//class A
//{
//public:
//	void fun()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "B : public A" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	// 调用之类自己的
//	b.fun(1); // B : public A
//	b.A::fun(); // A::func()
//
//	return 0;
//};


//class Person
//{
//public:
//	Person(const char* name = "Peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name = "", int num = 0)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student(const char* name = "", int num = 0)" << endl;
//	}
//
//	Student(const Student& s)
//		: Person(s) // 切割，子类的对象可以传给父类的引用
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			//operator=(s); //同样是切割，子类对象传给父类引用
//			// 注意，这么写是会崩溃的，operator= 不断重复调用自己，会造成栈溢出
//			// 这里需要调用父类的operator=，需要加上类域
//			Person::operator=(s);
//			_num = s._num;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//		return *this;
//	}
//
//	// 父子类的析构函数存在隐藏关系，虽然他们看上去名称不同
//	// 但由于的多态的需要，析构函数名被统一处理成destructor()
//	// 因此构成了隐藏关系
//	~Student()
//	{
//		// 不需要显示调用
//		//~Person();
//		//Person::~Person(); 
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //学号
//	//string _address = "西安";
//};
//
//int main()
//{
//	Student s1("李四", 1);
//	Student s2(s1);
//	Student s3("王五", 2);
//	s1 = s3;
//	return 0;
//}

//class A
//{
//public:
//	static A CreatObject()
//	//A CreatObject()
//	{
//		return A();
//	}
//private:
//	A()
//	{}
//};
//
//// 父类A的构造函数私有化后，B就无法构造对象了
//class B : public A
//{
//
//};
//
//int main()
//{
//	//B bb;
//	A aa = A::CreatObject();
//	return 0;
//}

//class Student; // 必须前置声明Student
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	//friend void Display(const Person& p, const Student& s); // 必须在父类子类都声明友元才行
//protected:
//	int _stuNum; // 学号
//};
//
//// Display是父类的友元，但不是子类的友元。友元关系不能继承下来，因此不能访问子类的成员
//void Display(const Person& p, const Student& s) {
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}


//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0; //静态成员需要在类外定义，类内声明
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	Person s;
//
//	// 任何一个类或者类的对象都可以访问静态成员
//	cout << " 人数 :" << Person::_count << endl; //人数 :5
//	cout << " 人数 :" << Student::_count << endl; //人数 :5
//	cout << " 人数 :" << s4._count << endl; //人数 :5
//	cout << " 人数 :" << s._count << endl; //人数 :5
//	cout << " 人数 :" << s2._count << endl; //人数 :5
//
//	// 访问的是同一个，地址也就是相同的
//	cout << &Person::_count << endl; // 00D1E3DC
//	cout << &Student::_count << endl; // 00D1E3DC
//	cout << &s4._count << endl; // 00D1E3DC
//	cout << &s._count << endl; // 00D1E3DC
//	cout << &s2._count << endl; // 00D1E3DC
//
//	return 0;
//}


//class Person
//{
//public:
//	string _name; // 姓名
//	int _a[10000];
//};
////class Student : virtual public Person
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
////class Teacher : virtual public Person
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	//加了virtual 虚拟继承，2个问题都解决了
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";
//
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//
//	cout << sizeof(a) << endl; //40072
//	return 0;
//}

//class A 
//{
//public:
//	//static int _a;
//	int _a;
//};
////int A:: _a = 0;
//
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A 
//{
//public:
//	int _c;
//};
//class D : public B, public C 
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	//D d1;
//	//D d2;
//	//// 地址相同
//	//cout << &d1._a << endl; // 002EA138
//	//cout << &d2._a << endl; // 002EA138
//
//	B b;
//	b._a = 10;
//	b._b = 20;
//
//	B* ptr1 = &d;
//	B* ptr2 = &b;
//
//	cout << ptr1->_a << endl;
//	cout << ptr2->_a << endl;
//	cout << ptr1->_b << endl;
//	cout << ptr2->_b << endl;
//
//	return 0;
//}


//class A{};
//
//// 继承
//class B : public A{};
//
//class C{};
//
//// 组合
//class D {
//	C _c;
//};



//class A
//{
//public:
//
//  void f() { cout << "A::f()" << endl; }
//  int a;
//};
//
//
//
//class B : public A
//
//{
//
//public:
//
//	void f(int a) { cout << "B::f()" << endl; }
//
//	int a;
//
//};
//
//
//
//int main()
//
//{
//
//	B b;
//
//	b.f();
//
//	return 0;
//
//}