#include<iostream>
#include<string>
using namespace std; 

class solution
{
public:
	int StrToInt(string str)
	{
		int result = 0;
		int flags = 1;//1表示正数，0表示负数

	//字符串为空，返回0
		if (str.size() == 0)
		{
			return 0;
		}

		if (str[0] == '+')
		{
			flags = 1;
		}

		if (str[0] == '-')
		{
			flags = 0;
		}

		int beishu = 1;
		for (int i = str.size() - 1; i > 0; i--)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				result = result + (str[i] - '0')*beishu;
				beishu = beishu * 10;
			}
			else
			{
				return 0;
			}
		}
		if (str[0] == '+' || str[0] == '-')
		{
			result = flags * result;
		}
		else
		{
			result = result + (str[0] - '0') *beishu;
		}
		return result;
	}
};

int main()
{
	solution s;
	cout << s.StrToInt("+2147483647") << endl;
	cout << s.StrToInt("1a33") << endl;
	system("pause");
	return 0;
}
