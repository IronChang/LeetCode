#include<iostream>
using namespace std;

int Add(int aint b)
{
	return b==0?a:Add(a^b,((a&b)>>1));
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<Add(a,b)<<endl;
	 } 
	return 0;
} 
