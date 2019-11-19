#include<iostream>

//(()()) 
using namespace std;
	bool chkParenthesis(string A, int n) {
		int count = 0;
		if (A.size() % 2 == 1)
			return false;
		for (int i = 0; i<A.size(); i++)
		{
			if (A[i] != '('&&A[i] != ')')
				return false;
			if (A[i] == '(')
				count++;
			if (A[i] == ')')
				count--;

		}
		if (count == 0)
			return true;
		return false;
	}


int main()
{
	string s;
	getline(cin, s);
	cout<<chkParenthesis(s, s.size())<<endl;
	system("pause");
	return 0;
}
