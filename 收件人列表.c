// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> vs;
	int n;
	while (cin >> n)
	{
		getchar();
		vs.resize(n);
		for (int i = 0; i < n; i++){
			getline(cin, vs[i]);
		}

		for (int j = 0; j < n; j++)
		{
			int pos = 0;
			if (vs[j].find(',', pos) != string::npos || vs[j].find(' ', pos) != string::npos)
			{
				//说明人名中可能存在逗号或者空格
				vs[j].insert(0, "\"");
				vs[j] += "\"";				
			}
		}

		for (int i = 0; i < n; i++)
		{
			cout << vs[i];
			if (i < n - 1) cout << ", ";
		}
		cout << endl;

	}


	return 0;
}