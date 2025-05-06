// main.cpp
#include "Person.h"
#include "Stack.h"
void testPerson()
{
	Person p1("张三", "男", 20);
	p1.show();

	Person p2(p1);
	p2.show();

	Person p3;
	p3 = p1;
	p3.show();
}

void testStack()
{
	Stack<int> stack;
	try
	{
		stack.push(10);
		stack.push(20);
		stack.push(30);

		std::cout << "Stack size: " << stack.size() << std::endl;
		std::cout << "Top element: " << stack.peek() << std::endl;

		std::cout << "Popped element: " << stack.pop() << std::endl;
		std::cout << "Stack size after pop: " << stack.size() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
int main()
{

	// testPerson();
	testStack();
	return 0;
}