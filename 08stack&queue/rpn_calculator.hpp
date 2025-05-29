#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
// 判断字符是否是运算符
bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// 获取运算符优先级
int precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

// 应用运算符进行计算
double applyOp(double a, double b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return a / b;
	}
	return 0;
}

// 中缀表达式转逆波兰表达式的辅助函数（处理子表达式）
std::vector<std::string> infixToRPN(const std::string &infix, size_t &pos)
{
	std::vector<std::string> output;
	std::stack<char> operators;

	for (; pos < infix.length(); pos++)
	{
		char c = infix[pos];

		// 跳过空白字符
		if (isspace(c))
			continue;

		// 如果是数字，提取完整数字
		if (isdigit(c) || c == '.')
		{
			std::string num;
			// 如果是连续的数字，提取完整
			while (pos < infix.length() && (isdigit(infix[pos]) || infix[pos] == '.'))
			{
				num += infix[pos++];
			}
			pos--; // 回退一个位置，因为for循环会再增加pos
			output.push_back(num);
		}
		// 如果是左括号，递归处理括号内的子表达式
		else if (c == '(')
		{
			pos++; // 跳过左括号
			std::vector<std::string> subRPN = infixToRPN(infix, pos);
			output.insert(output.end(), subRPN.begin(), subRPN.end());
		}
		// 如果是右括号，结束当前子表达式处理
		else if (c == ')')
		{
			// 弹出所有运算符到output存储起来，直到遇到左括号
			while (!operators.empty() && operators.top() != '(')
			{
				output.push_back(std::string(1, operators.top()));
				operators.pop();
			}
			if (!operators.empty())
				operators.pop(); // 弹出左括号
			return output;
		}
		// 如果是运算符+-*/
		else if (isOperator(c))
		{
			// 弹出优先级大于或等于当前运算符的所有运算符
			// 遇到运算符，与栈顶运算符比较，优先级<=就出栈顶运算符，优先级>就入栈
			// 如果栈空，就入栈
			while (!operators.empty() && precedence(operators.top()) >= precedence(c))
			{
				output.push_back(std::string(1, operators.top()));
				operators.pop();
			}
			operators.push(c);
		}
		else
		{
			throw std::runtime_error("Invalid character in expression");
		}
	}

	// 弹出所有剩余的运算符
	while (!operators.empty())
	{
		if (operators.top() == '(')
			throw std::runtime_error("Mismatched parentheses");
		output.push_back(std::string(1, operators.top()));
		operators.pop();
	}

	return output;
}

// 中缀表达式转逆波兰表达式的主函数
std::vector<std::string> infixToRPN(const std::string &infix)
{
	size_t pos = 0;
	return infixToRPN(infix, pos);
}

// 计算逆波兰表达式的值
double evaluateRPN(const std::vector<std::string> &tokens)
{
	std::stack<double> values;

	for (const std::string &token : tokens)
	{
		// 如果是运算符，弹出两个操作数进行计算
		if (token.length() == 1 && isOperator(token[0]))
		{
			double b = values.top();
			values.pop();
			double a = values.top();
			values.pop();
			values.push(applyOp(a, b, token[0]));
		}
		// 否则转换为数字压入栈
		else
		{
			try
			{
				values.push(stod(token));
			}
			catch (const std::invalid_argument &e)
			{
				throw std::runtime_error("Invalid token in RPN expression");
			}
		}
	}

	if (values.size() != 1)
		throw std::runtime_error("Invalid RPN expression");

	return values.top();
}

// 主函数
void testRPNCalculator()
{
	std::string infix = "1+3-(1-2+5)*(1*3-2)-8*7";
	std::cout << "Enter infix expression: ";
	// getline(std::cin, infix);

	try
	{
		// 转换为RPN
		std::vector<std::string> rpn = infixToRPN(infix);

		// 输出RPN表达式
		std::cout << "RPN expression: ";
		for (const std::string &token : rpn)
		{
			std::cout << token << " ";
		}
		std::cout << std::endl;

		// 计算结果
		double result = evaluateRPN(rpn);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}