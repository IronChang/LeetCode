#include<iostream>
#include<string>
using namespace std;
int Fun(string s)
{
    int ret=0;
    for(int i=0;i<s.size();i++)
    {
        ret=ret*26+s[i]-'a';//从字符串a开始到这个字符串有多少个不同的字符串
    }
    return ret;
}
int main()
{
    string str1,str2;
    int l1,l2;
    while(cin>>str1>>str2>>l1>>l2)
    {
        cout<<(Fun(str2)-Fun(str1)-1)%1000007<<endl;//他两之间的差距
    }
    return 0;
}
