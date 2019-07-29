#include<stdio.h>

//求100 - 200 之间的素数(质数) 

/*int main()
{
	int i = 0;
	int count = 0;
	
	for(i=100 ;i <= 200; i++)
	{
		int j = 0;
		for(j=2 ; j<=i ;j++)
		{
			if(i%j == 0)
			{
				break;
			}
		 } 
		 
		 if(j == i)
		 {
		 	printf("%d ",i);\
		 	count++;
		 }
	}
	printf("\n");
	printf("素数个数:%d",count);
	return 0;
} 
*/

//判断1000 - 2000之间的闰年 
/*int main()
{
	int count = 0;
	for(int i = 1000; i <= 2000; i++) 
	{
		if(i%100 != 0 && i%4 == 0 || i%400 == 0)
		{
			printf("%d ",i);
			count++;
		}
	}
	printf("闰年数: %d",count);
	return 0;
}*/

//输出乘法口诀表

/*int main()
{
	int i = 0;
	for(i= 1 ; i<= 9;i++)
	{
		for(int j = 1;j<=i;j++)
		{
			printf("%d * %d = %2d  ",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
 } 
*/


