

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n)
    {
        int sum=0;
        for(int i=2;i<sqrt(n);i++)
        {
            if(n%i==0)
                sum++;//�������
            while(n%i==0)
                n/=i;
        }
        //n������1 ����ִ���sqrt(n)������ 
        if(n!=1)sum+=1;
        cout<<sum<<endl;
    }
    return 0;
}
