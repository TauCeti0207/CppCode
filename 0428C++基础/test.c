#include "../Stack_CPP/Stack.h"


bool isValid(const char* s) {
	// ���ȥ�����ַ�����Ҫ��int�ĳ�char
	Stack st;
	StackInit(&st);
	while (*s)
	{
		// ��������ջ
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
			++s;
		}
		// �����ų�ջ���ж��Ƿ�ƥ��
		else
		{
			// Ϊ�գ�˵��û�������ţ�ֻ��������
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}
			char top = StackTop(&st);
			StackPop(&st);// ȡ����Ҫpop��
			if ((top == '[' && *s != ']')
				|| (top == '(' && *s != ')')
				|| (top == '{' && *s != '}'))
			{
				StackDestroy(&st); // ����֮ǰһ��Ҫ���٣���Ȼ�����ڴ�й¶
				return false;
			}
			// ƥ���˾ͼ����ж�
			else
				++s;
		}
	}
	// ���ֻ�������ţ�whileѭ��һֱ�ڵ�һ��if���棬�޷���ѭ������return false ��˵���ѭ�����洦��ֻ�������ţ�Stack��Ϊ�գ����ص���false
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

