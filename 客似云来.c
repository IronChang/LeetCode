// write your code here cpp
#include<iostream>
using namespace std;

long long fib(int n)
{
    if (n <= 2)
	{
		return 1;
	}
	else
	{
		long long a = 1;
		long long b = 1;
		long long c = 0;
		for (int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

int main()
{
   int from,to;
    while(cin>>from>>to)
    {
    long long sum = 0;
        while(from<=to)
        {
            sum+=fib(from);
            ++from;
        }
        cout<<sum<<endl;
    }
    return 0;
}