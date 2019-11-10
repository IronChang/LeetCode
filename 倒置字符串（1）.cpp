#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	//整体进行逆转
	reverse(s.begin(), s.end());

	//进行部分逆转
	string::iterator start = s.begin();
	string::iterator end = start;
	while (end != s.end())
	{
		//找空格，遇见空格停下
		while (end != s.end() && *end != ' ')
		{
			end++;
		}
		
		if (end != s.end())
		{
			reverse(start, end);//进行局部反转
			end++;
			start = end;
		}
		else
		{
			reverse(start, end);//进行局部反转
		}
	}
	cout << s << endl;

	return 0;
}
