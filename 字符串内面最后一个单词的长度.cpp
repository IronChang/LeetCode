#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    //getline���ڽ���һ���ַ���
    while(getline(cin,s))
    {
        size_t pos = s.rfind(' ')+1;
        string tmp = s.substr(pos);
        cout<<tmp.size()<<endl;
    }
    return 0;
}
