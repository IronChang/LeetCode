/*
斐波那锲数列的非递归实现
思路：循环控制
*/

int Fib1(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;

	if ( n <= 2)
	{
		return 1;
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

int Fib2(int n)
{
	if (n == 2 || n == 1)
	{
		return 1;
	}
	else
	{
		return Fib2(n - 2) + Fib2(n - 1);
	}
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", Fib1(num));
	printf("%d\n", Fib2(num));
	system("pause");
	return 0;
}
