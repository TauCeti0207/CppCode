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
//// ���뽨���ڹ��м̳еĻ�����
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	s._name = "����";
//	s._age = 18;
//	s._sex = "��";
//
//	// ������������ ����/ָ��/���� -- �﷨��Ȼ֧�֣�û������ת����Ҳ�Ͳ�������ʱ����
//	p = s;
//	Person& rp = s;
//	Person* ptrp = &s;
//	cout << s._age << endl; // 18
//	cout << p._age << endl; // 18
//
//	// ָ����ͬһ��ռ�
//	cout << &s << endl; // 012FFAA0
//	cout << &rp << endl; // 012FFAA0
//	cout << ptrp << endl; // 012FFAA0
//	rp._age++;
//	ptrp->_age++;
//	cout << s._age << endl; // 20
//	cout << p._age << endl; // 18
//
//	// ���಻�ܸ�ֵ��֮�࣬��ʹǿתҲ����
//	//s = (Student)p;
//
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	ptrp = &s;
//	Student* ps1 = (Student*)ptrp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//
//	ptrp = &p;
//	Student* ps2 = (Student*)ptrp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//	return 0;
//}


// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		// �����˸����ͬ����Ա����
//		cout << " ѧ��:" << _num << endl; // 999
//		// �����������
//		cout << " ���֤��:" << Person::_num << endl; // 111
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//	return 0;
//}

// ��2��fun��ϵ��Ȼ������
// ���ﲻ�����أ���������Ҫ����ͬһ��������
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
//	// ����֮���Լ���
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
//	string _name; // ����
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
//		: Person(s) // �и����Ķ�����Դ������������
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			//operator=(s); //ͬ�����и������󴫸���������
//			// ע�⣬��ôд�ǻ�����ģ�operator= �����ظ������Լ��������ջ���
//			// ������Ҫ���ø����operator=����Ҫ��������
//			Person::operator=(s);
//			_num = s._num;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//		return *this;
//	}
//
//	// ����������������������ع�ϵ����Ȼ���ǿ���ȥ���Ʋ�ͬ
//	// �����ڵĶ�̬����Ҫ��������������ͳһ�����destructor()
//	// ��˹��������ع�ϵ
//	~Student()
//	{
//		// ����Ҫ��ʾ����
//		//~Person();
//		//Person::~Person(); 
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //ѧ��
//	//string _address = "����";
//};
//
//int main()
//{
//	Student s1("����", 1);
//	Student s2(s1);
//	Student s3("����", 2);
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
//// ����A�Ĺ��캯��˽�л���B���޷����������
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

//class Student; // ����ǰ������Student
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	//friend void Display(const Person& p, const Student& s); // �����ڸ������඼������Ԫ����
//protected:
//	int _stuNum; // ѧ��
//};
//
//// Display�Ǹ������Ԫ���������������Ԫ����Ԫ��ϵ���ܼ̳���������˲��ܷ�������ĳ�Ա
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
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//
//int Person::_count = 0; //��̬��Ա��Ҫ�����ⶨ�壬��������
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
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
//	// �κ�һ���������Ķ��󶼿��Է��ʾ�̬��Ա
//	cout << " ���� :" << Person::_count << endl; //���� :5
//	cout << " ���� :" << Student::_count << endl; //���� :5
//	cout << " ���� :" << s4._count << endl; //���� :5
//	cout << " ���� :" << s._count << endl; //���� :5
//	cout << " ���� :" << s2._count << endl; //���� :5
//
//	// ���ʵ���ͬһ������ַҲ������ͬ��
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
//	string _name; // ����
//	int _a[10000];
//};
////class Student : virtual public Person
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
////class Teacher : virtual public Person
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	//����virtual ����̳У�2�����ⶼ�����
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	//a._name = "peter";
//
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
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
//	//// ��ַ��ͬ
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
//// �̳�
//class B : public A{};
//
//class C{};
//
//// ���
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