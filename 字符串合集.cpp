/*��Ŀ����
����һ���ַ�����������ַ����������ַ�����
ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ�������
*/ 
#include<iostream>
using namespace std;
int main()
{
    string s;    
    while(cin>>s)
    {
    	//��� 
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
