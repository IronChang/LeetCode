#include<iostream>
#include<cmath>
using namespace std;

bool is_sunum(const int num)
{
	//所谓素数是指除了 1 和它本身以外，不能被任何整数整除的数，例如17就是素数，因为它不能被 2~16 的任一整数整除
	//m 不必被 2 ~ m-1 之间的每一个整数去除，只需被 2 ~ sqrt((double)num) 之间的每一个整数去除就可以了。
	int k = (int)sqrt((double)num);
	int count = 1;
	for (int i = 2; i <= k; i++)
	{
		if (num % i == 0)
		{
			count = 0;
			break;
		}
	}

	if (count == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int b;
	cin >> b;

	//非偶数异常输入
	while (b % 2 != 0)
		return 0;

	int j, distance, t = 0;
	int min = 0;
	for (j = 2; j <= b / 2; j++)
	{
		if (is_sunum(j) && is_sunum(b - j))
		{
			distance = b - j - j;
			if (min == 0 || min > distance)
			{
				min = distance;
				t = j;
			}
		}
	}
	cout << t << endl;
	cout << (b - t) << endl;
	system("pause");
	return 0;
}
