#include<iostream>
using namespace std;

int main()
{
	//��������ε�����
	//1.�����߶���Ҫ����0��
	//2.��������֮�Ͷ�Ҫ���ڵ�����
	//3.��������֮�ҪС�ڵ�����
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "No" << endl;
		}
		if ( a+b>c && a+c>b && b+c>a)//2.��������֮�Ͷ�Ҫ���ڵ����ߣ�����������ͬ��һ����������
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
