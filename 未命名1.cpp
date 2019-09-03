#include<stdio.h>

int fun(int a,int b)
{
	if(a>b)
	return (a+b);
	else
	return (a-b);
}

int x = 3;

void inc()
{
	static int x = 1;
	x*=(x+1);
	printf("%d\n",x);
	return;
}

int main()
{
	//int x = 3, y = 8,z = 6,r;
	//r = fun(fun(x,y),2*z);
	//printf("%d\n",a);
	
	int i;
	for(i=1;i<x;i++)
	{
		inc();
	}
	
	return 0;
 } 
 
 int func(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);
	}

	return count;
}

int main()
{
	int i = func(2019);
	printf("%d\n", i);
	system("pause");
	return 0;
}


