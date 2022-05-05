#include "../Stack_CPP/Stack.h"


bool isValid(const char* s) {
	// 入进去的是字符，需要将int改成char
	Stack st;
	StackInit(&st);
	while (*s)
	{
		// 左括号入栈
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
			++s;
		}
		// 右括号出栈，判断是否匹配
		else
		{
			// 为空，说明没有左括号，只有右括号
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}
			char top = StackTop(&st);
			StackPop(&st);// 取完了要pop掉
			if ((top == '[' && *s != ']')
				|| (top == '(' && *s != ')')
				|| (top == '{' && *s != '}'))
			{
				StackDestroy(&st); // 返回之前一定要销毁，不然会有内存泄露
				return false;
			}
			// 匹配了就继续判断
			else
				++s;
		}
	}
	// 如果只有左括号，while循环一直在第一个if里面，无法在循环里面return false 因此得在循环外面处理，只有左括号，Stack不为空，返回的是false
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}

int main()
{
	printf("%d\n", isValid("[]{}"));
	printf("%d\n", isValid("[{]}()"));
	printf("%d\n", isValid("[]()"));
}

