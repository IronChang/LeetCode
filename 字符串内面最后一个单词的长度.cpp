#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    //getline用于接受一个字符串
    while(getline(cin,s))
    {
        size_t pos = s.rfind(' ')+1;
        string tmp = s.substr(pos);
        cout<<tmp.size()<<endl;
    }
    return 0;
}
