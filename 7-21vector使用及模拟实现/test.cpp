#include "vector.h"
void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<double> v2;
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);

	vector<string> v3;
	v3.push_back("李白");
	v3.push_back("杜甫");
	v3.push_back("苏轼");
	v3.push_back("白居易");

	vector<int> v4(10, 5);

	vector<string> v5(++v3.begin(), --v3.end());
	string s = "hello world";

	vector<char> v6(s.begin(), s.end());

	vector<string> v7(4); //默认初始化为空字符串

	vector<vector<int> > v8;  //注意空格。这里相当于二维数组int a[n][n];
}

void test_vector2()
{
	// 遍历
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 1、下表+[]
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] += 1;
		cout << v[i] << " ";
	}
	cout << endl;

	// 2.迭代器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 3.范围for
	for (auto& e : v)
	{
		e += 1;
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v1;
	vector<char> v2;
	cout << v1.max_size() << endl;
	cout << v2.max_size() << endl;
}

// 查看扩容情况
void test_vector4()
{
	size_t sz;
	std::vector<int> foo;
	//foo.reserve(100); // 如果预知到大概插入多少数据利用reserve开好足够的空间
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector5()
{
	vector<int> countV;
	countV.resize(10, 1); // 10个1
	for (auto e : countV)
	{
		cout << e << " ";
	}
	cout << endl;

	countV.resize(5); // 只保留下5个1
	for (auto e : countV)
	{
		cout << e << " ";
	}
	cout << endl;

	countV.resize(8, 10); // 5个1后面接上3个10
	for (auto e : countV)
	{
		cout << e << " ";
	}
	cout << endl;

	countV.resize(12); // 最后补上4个0凑足12
	for (auto e : countV)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector6()
{
	std::vector<int> foo;
	foo.reserve(100);
	foo.resize(10); //原来100个空间
	cout << foo.size() << endl;
	cout << foo.capacity() << endl;
	foo.shrink_to_fit(); // 把capacity缩到和size一样大
	cout << foo.size() << endl;
	cout << foo.capacity() << endl;
}

void test_vector7()
{
	// 遍历
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.insert(v.begin(), -1);
	v.insert(v.begin(), -2);
	v.insert(v.begin(), -3);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin() + 7, 300); // 在任意位置插入都行
	//v.insert(v.begin()+8, 300); //越界了 err
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());
	v.erase(v.begin());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin() + 1, v.begin() + 4);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector8()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(6);
	v.push_back(3);
	v.push_back(9);
	v.push_back(2);
	v.push_back(0);
	v.push_back(8);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//排升序
	sort(v.begin(), v.end()); // 默认是小于，就是升序
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 排降序 利用仿函数
	// 构造了一个匿名对象 
	//greater<int> g;
	//sort(v.begin(), v.end(), g); // 这样也行
	sort(v.begin(), v.end(), greater<int>()); // > 就是降序
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector9()
{
	vector<vector<int>> vv;
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}

class Solution {
	// const char* 的类型也行
	// 单参数隐式类型转换，直接被编译器优化成构造
	string _numToStr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	void _letterCombinations(string digits, size_t di, string combinStr, vector<string>& retV)
	{
		// 递归结束条件
		if (di == digits.size())
		{
			retV.push_back(combinStr);
			return;
		}

		// 传过来的数字串转换为数字，再映射到对应的字符串
		int num = digits[di] - '0';
		string str = _numToStr[num];
		for (auto ch : str)
		{
			// 递归去组合
			// 不能用combinStr += ch 会累积上去
			_letterCombinations(digits, di + 1, combinStr + ch, retV);
		}

	}
	vector<string> letterCombinations(string digits) {
		vector<string> retV;
		// 考虑空串
		if (digits.size() == 0)
			return retV;
		size_t i = 0;
		string str;
		_letterCombinations(digits, i, str, retV);

		return retV;
	}
};

void test_vector10()
{
	// 直接构造匿名对象
	vector <string> v = Solution().letterCombinations("234");
}

class Solution2 {
public:
	void _FindGreatestSumOfSubArray(vector<int> array, vector<int> subArr, size_t di, vector<int>& retV)
	{
		vector<int> arr(array.begin(), array.begin() + di);
		_FindGreatestSumOfSubArray(array, arr, di + 1, retV);
		// 把所有子数组的和放进一个数组里面，然后再排序
		if (di == subArr.size())
		{
			int tmp = 0;
			for (auto e : subArr)
			{
				tmp += e;
			}
			retV.push_back(tmp);
			return;
		}
	}
	int FindGreatestSumOfSubArray(vector<int> array) {
		size_t i = 0;
		vector<int> subArr;
		vector<int> retV;
		_FindGreatestSumOfSubArray(array, subArr, i, retV);

		sort(retV.begin(), retV.end());
		return retV.back();
	}
};

void test_vector11()
{
	vector<int> array = { 1,-2,3,10,-4,7,2,-5 };
	int ret = Solution2().FindGreatestSumOfSubArray(array);
}

void test_yzq_vector1()
{
	yzq::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	yzq::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		*it += 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	for (size_t i = 0; i < v1.size(); ++i)
	{
		v1[i] -= 1;
		cout << v1[i] << " ";
	}
	cout << endl;

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_yzq_vector2()
{
	yzq::vector<int> v1;
	// 更多的还是利用resize完成初始化
	v1.resize(15, -2);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_yzq_vector3()
{
	yzq::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.insert(v1.begin(), 0);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_yzq_vector4()
{
	// 在所有的偶数前面插入一个20
	yzq::vector<int> v1;
	//v1.reserve(20);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	yzq::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			it = v1.insert(it, 20);
			++it;
		}
		++it;
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vs_vector1()
{
	std::vector<int> v1;
	v1.reserve(10);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	cout << v1.size() << " " << v1.capacity() << endl;
	auto pos = find(v1.begin(), v1.end(), 2);
	if (pos != v1.end())
	{
		v1.insert(pos, 20);
	}
	cout << *pos << endl;
	*pos = 10;
	cout << *pos << endl;
}

void test_yzq_vector5()
{
	yzq::vector<int> v1;
	//v1.reserve(10);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	cout << v1.size() << " " << v1.capacity() << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	auto pos = find(v1.begin(), v1.end(), 2);
	if (pos != v1.end())
	{
		v1.erase(pos);
	}
	cout << *pos << endl;
	*pos = 10;
	cout << *pos << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v1.size() << " " << v1.capacity() << endl;
}

void test_vs_vector5()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	cout << v1.size() << " " << v1.capacity() << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	auto it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			it = v1.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v1.size() << " " << v1.capacity() << endl;
}

void test_yzq_vector6()
{
	std::string s("hello");
	yzq::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	yzq::vector<int> v1(v.begin(), v.end());
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	yzq::vector<char> v2(s.begin(), s.end());
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_yzq_vector7()
{
	std::string s("hello");
	yzq::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	yzq::vector<int> v1(v);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	yzq::vector<int> v2 = v;
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_yzq_vector8()
{
	yzq::vector<int> v(10, 2);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	yzq::vector<char> v2(10, 'x');
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

class Solution3 {
public:
	yzq::vector<vector<int>> generate(int numRows) {
		yzq::vector<vector<int>> vv;
		vv.resize(numRows); // 设置总共的行数，默认都初始化为0
		for (size_t i = 0; i < vv.size(); ++i)
		{
			// 每一行i+1个数
			vv[i].resize(i + 1);
			// vv[i][0] = 1, vv[i][vv[i].size()-1] = 1;
			vv[i].front() = 1, vv[i].back() = 1; //利用函数也行
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}

		return vv;
	}
};

void test_yzq_vector9()
{
	yzq::vector<vector<int>> vv = Solution3().generate(5);
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}

class Solution4 {
	string _numToStr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	void _letterCombinations(string digits, vector<string>& retV, size_t di, string combinStr)
	{
		if (di == digits.size())
		{
			retV.push_back(combinStr);
			return;
		}
		int num = digits[di] - '0';
		string str = _numToStr[num];
		for (auto ch : str)
		{
			_letterCombinations(digits, retV, di + 1, combinStr + ch);
		}
	}
	vector<string> letterCombinations(string digits) {
		size_t i = 0;
		vector<string> retV;
		string combinStr;
		_letterCombinations(digits, retV, i, combinStr);

		return retV;
	}
};

void test_yzq_vector10()
{
	Solution4().letterCombinations("2");
}

int main()
{
	test_yzq_vector10();
	return 0;
}