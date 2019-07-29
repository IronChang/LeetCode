#include<stdio.h>

//交换两个数

//建立中建变量 - 传值
/*int main()
{
	int a = 5,b = 10,c;
	
	printf("交换前：a = %d,b = %d\n",a,b);
	
	c=a;
	a=b;
	b=c;
	
	printf("交换后：a = %d,b = %d\n",a,b);
	return 0;
 } */
 
 //不建立中间变量
 /*int main()
 {
 	int a=5,b=10;
 	
 	printf("交换前：a = %d,b = %d\n",a,b);
 	
 	a=a+b;
 	b=a-b;	
 	a=a-b;
 
 	
 	printf("交换后：a = %d,b = %d\n",a,b);
 	return 0;
  } */
  
  //求10个数中的最大值
  
  /*int main()
  {
  	int arr[10] = { 9, 8, 5, 3, 6, 2, 1, 4, 7, 45 };
  	
  	int a = 0;
  	
  	for(int i = 0; i < sizeof(arr)/sizeof(int);i++)
  	{
  		if(arr[i]>a)
  		{
  			a = arr[i];
		}
	  }
	  
	  printf("最大值： %d",a);
  	return 0;
  } */
  
  
  //求两个数最大公约数
  
/*  int main()
  {
  	int m,n,i = 0;
	scanf("%d %d",&m,&n);
	
	if(n > m)
	{
		int tmp = n;
		n = m;
		m = tmp;
	} 
	 
	 for(i = 1 ;i <= n ; i++)
	 {
	 	
	 	if(n%i == 0 && m%i == 0)
	 	{
	 		printf("%d \n",i);
		}
	}
	
  	return 0;
   } */
   
   
   //三个数从大到小输出
   
/*   int main()
   {
   	int a,b,c,t;
   	scanf("%d %d %d",&a,&b,&c);
   	
   	if(a>b)
   	{
   	   t = a;
   	   a = b;
   	   b = t;
	}
	
	if (a > c)
	{
		t = a;
		a = c;
		c = t;
    }
	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}
   	
   	printf("%d %d %d",c,b,a);
   	return 0;
   } 
   */
   
   //交换数组中的内容
  /* int main()
   {
   	int a[]= {1,2,3,4,5};
   	int b[]= {7,5,6,4,2};
   	int i  = 0;
   	int j=0;
   	for(i= 0;i<sizeof(a)/sizeof(int);i++)
   	{
   		int tmp = a[i];
   		a[i] = b[i];
   		b[i] = tmp;
	   }
	   
	   printf("数组a：");
	   for(j= 0;j<sizeof(a)/sizeof(int);j++)
	   {
	   	printf("%d ",a[j]);
	   }
	   printf("\n");
	   printf("数组b：");
	   	   for(j= 0;j<sizeof(a)/sizeof(int);j++)
	   {
	   	printf("%d ",b[j]);
	   }
   	return 0;
	}
	*/
	
	//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值
	
/*	int main()
	{
		int i = 0;
		double sum1 = 0;
		double sum2 = 0;
		
		for(i=1;i<=100;i++)
		{
			sum1 += (1.0/i);
		}
		
		for(i=2;i<=100;i++)
		{
			sum2 += (1.0/i);
		}
		
		printf("%lf ",sum1-sum2);
	 } 
	 */
	 
	 
	 //编写程序数一下 1到 100 的所有整数中出现多少次数字9
	 int main()
	 {
	 	int i=0;
	 	int k=0;
	 	
	 	for(i=1;i<=100;i++)
		 {
		 		 	//十位的9
		    if(i%10 == 9)
		    {
		    	k++;
			}
	         	//个位的9 
		 	if(i/10 == 9)
		 	{
		 		k++;
			 }
		  } 
printf("%d ",k);
	 }
