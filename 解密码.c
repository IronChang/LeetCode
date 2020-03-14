#include<iostream>
#inlcude<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		string::iterator it = s.begin();
		while (it != s.end())
		{
			if (*it >= '0'&& *it <= '9')
			{
				cout << *it;
			}
			it++;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}