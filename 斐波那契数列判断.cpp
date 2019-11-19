#include<iostream>
using namespace std;

int fib(int n)
{
	int count = 0;
	//求得斐波那契数列
	int a = 0;
    int b = 1;
	int c = 0;
	while (1)
	{
		c = a + b;
		if (n <= c)
		{
			break;
		}
		a = b;
		b = c;
	}
	if (n == c)
	{
		return 0;
	}
	if ((n - b) > (c - n))
	{
		return c - n;
	}
	else
	{
		return n - b; 
	}
}
int main()
{
	int n = 0;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}
