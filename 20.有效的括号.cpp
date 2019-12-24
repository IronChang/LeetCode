#include<iostream>
#include<stack>
using namespace std; 
//合法到的括号
 class Solution {
 public:
	 bool isValid(string s) {
		 stack<char> ss;
		 int len = s.size();
		 if (len == 1)
			 return false;
		 if (len == 0)
			 return true;
		 char c;
		 for (int i = 0; i < len; ++i)
		 {
			 if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
				 ss.push(s[i]);
			 else
			 {
				 if (ss.empty())
					 return false;
				 if (s[i] == ')')
					 c = s[i] - 1;
				 else
					 c = s[i] - 2;
				 if (c == ss.top())
					 ss.pop();
				 else
					 return false;
			 }
		 }
		 if (ss.empty())
			 return true;
		 else
			 return false;

	 }
 };


int main()
{
	Solution s;
	cout << s.isValid("([)]") << endl;
	system("pause");
	return 0;
}
