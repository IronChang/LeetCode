#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
	int n;
	
	string s;
	cin >> n >> s;
	vector<int> v(n);
	if (n <= 4) //歌曲数量小于等于4
	{
		int select = 1;

		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == 'U')
			{
				if (select == 1)
				{
					select = n;
				}
				else
				{
					select--;
				}
			}

			if (s[i] == 'D')
			{
				if (select == n)
				{
					select = 1;
				}
				else
				{
					select++;
				}
			}
		}
		//输出当前列表中的歌
		for (size_t i = 1; i <= v.size(); i++)
		{
			cout << i << " ";
		}
		cout << endl;

		//输出当前光标所在位置的歌曲
		cout << select << endl;
	}
	else //歌曲数量大于4
	{
		int select = 1;

		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == 'U')
			{
				if (select == 1)
				{
					select = n;
				}
				else
				{
					select--;
				}
			}
			if (s[i] == 'D')
			{
				if (select == n)
				{
					select = 1;
				}
				else
				{
					select++;
				}
			}
		}

		//输出当前列表中的歌
		//1.特殊翻页
		if ((select == 1) || ( select == 10))
		{
			if (select == 1)
			{
				//cout << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
				for (int i = 1; i <= 4; i++)
				{
					cout << i << " ";
				}
				cout << endl;
			}
			else
			{
				for (int i = n - 3; i <= n; i++)
				{
					cout << i << " ";
				}
				cout << endl;
			}
		}
		else//2.一般翻页
		{
			int i = select;
			int k = 4;
			if (s[s.size() - 1] == 'U')
			{
				while (k--)
				{
					cout << i++ << " ";
				}
				cout << endl;
			}
			if (s[s.size() - 1] == 'D')
			{
				for (int i = select - 3; i <= select; i++)
				{
					cout << i << " ";
				}
				cout << endl;
			}
		}
		//输出当前光标所在位置的歌曲
		cout << select << endl;
	}
	system("pause");
	return 0;
}
