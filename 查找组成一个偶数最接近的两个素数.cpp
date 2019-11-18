#include<iostream>
#include<cmath>
using namespace std;

bool is_sunum(const int num)
{
	//��ν������ָ���� 1 �����������⣬���ܱ��κ�������������������17������������Ϊ�����ܱ� 2~16 ����һ��������
	//m ���ر� 2 ~ m-1 ֮���ÿһ������ȥ����ֻ�豻 2 ~ sqrt((double)num) ֮���ÿһ������ȥ���Ϳ����ˡ�
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

	//��ż���쳣����
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
