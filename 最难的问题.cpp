#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				i++;
			}

			s[i] -= 5;

			if (s[i] < 'A')
			{
				s[i] += 26;
			}
			
		}
		cout << s << endl;
    }
	return 0;
}
