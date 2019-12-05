#include<iostream>
#include<algorithm>
using namespace std;

bool Is_prime(int num)
{
    int k = sqrt(num);
    for(int i = 2;i<=k;i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int M,N;
    while(cin>>M>>N)
    {
        int count = 0;
        for(int i = M;i<= N;i++)
        {
            if(Is_prime(i))
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

