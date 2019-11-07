/*题目描述
输入一个字符串，求出该字符串包含的字符集合
每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
*/ 
#include<iostream>
using namespace std;
int main()
{
    string s;    
    while(cin>>s)
    {
    	//标记 
        int hash[256] = {0};
        //for(auto ch : s)
        for(int ch = 0;ch<s.size();ch++)
        {
            if(hash[ch] == 0)
            {
                cout<<ch;
                hash[ch] = 1;
            }
        }
        cout<<endl;
    }
    return 0;
}
