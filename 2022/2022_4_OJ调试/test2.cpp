#include <iostream>
using namespace std;

long long quickPow(long long a, long long b, long long p)
{
	long long ans = 1, base = a;
	while (b > 0)
	{
		if (b & 1)
		{
			ans *= base;
			ans %= p;
		}

		base *= base;
		base %= p;
		b >>= 1;
	}
	return ans;
}

int main()
{
	long long a, b, p;
	cin >> a >> b >> p;
	long long ret = quickPow(a, b, p);
	printf("%ld^%ld mod %ld=%ld", a, b, p, ret);//Êä³ö
	return 0;
}