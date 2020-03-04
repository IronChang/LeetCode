// write your code here cpp
#include<string>
#include<iostream>
using namespace std;

int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        int res = 0;
        size_t pos = 0;
        while ((pos = s.find(t,pos)) != string::npos)
        {
            pos += t.size();
            ++res;
        }
 
        cout << res << endl;
    }
    return 0;
}
