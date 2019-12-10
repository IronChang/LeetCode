

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
                sum++;//除则除尽
            while(n%i==0)
                n/=i;
        }
        //n最后大于1 则出现大于sqrt(n)的因子 
        if(n!=1)sum+=1;
        cout<<sum<<endl;
    }
    return 0;
}
