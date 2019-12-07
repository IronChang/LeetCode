#include<iostream>
using namespace std;

int main()
{
	//组成三角形的条件
	//1.三条边都是要大于0的
	//2.任意两边之和都要大于第三边
	//3.任意两边之差都要小于第三边
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "No" << endl;
		}
		if ( a+b>c && a+c>b && b+c>a)//2.任意两边之和都要大于第三边，与条件三相同有一个成立即可
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
