#include<stdio.h>

//����������

//�����н����� - ��ֵ
/*int main()
{
	int a = 5,b = 10,c;
	
	printf("����ǰ��a = %d,b = %d\n",a,b);
	
	c=a;
	a=b;
	b=c;
	
	printf("������a = %d,b = %d\n",a,b);
	return 0;
 } */
 
 //�������м����
 /*int main()
 {
 	int a=5,b=10;
 	
 	printf("����ǰ��a = %d,b = %d\n",a,b);
 	
 	a=a+b;
 	b=a-b;	
 	a=a-b;
 
 	
 	printf("������a = %d,b = %d\n",a,b);
 	return 0;
  } */
  
  //��10�����е����ֵ
  
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
	  
	  printf("���ֵ�� %d",a);
  	return 0;
  } */
  
  
  //�����������Լ��
  
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
   
   
   //�������Ӵ�С���
   
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
   
   //���������е�����
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
	   
	   printf("����a��");
	   for(j= 0;j<sizeof(a)/sizeof(int);j++)
	   {
	   	printf("%d ",a[j]);
	   }
	   printf("\n");
	   printf("����b��");
	   	   for(j= 0;j<sizeof(a)/sizeof(int);j++)
	   {
	   	printf("%d ",b[j]);
	   }
   	return 0;
	}
	*/
	
	//����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ
	
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
	 
	 
	 //��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9
	 int main()
	 {
	 	int i=0;
	 	int k=0;
	 	
	 	for(i=1;i<=100;i++)
		 {
		 		 	//ʮλ��9
		    if(i%10 == 9)
		    {
		    	k++;
			}
	         	//��λ��9 
		 	if(i/10 == 9)
		 	{
		 		k++;
			 }
		  } 
printf("%d ",k);
	 }
