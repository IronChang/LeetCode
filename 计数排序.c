#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
//��������

void CountSort(int* a, int len)
{
	assert(a);
	//ͨ��max��min�������ʱ��������Ҫ���ٵĿռ��С
	int max = a[0];
	int min = a[0];
	int i=0; 
	for (i = 0; i < len; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//ʹ��calloc�����鶼��ʼ��Ϊ0
	int range = max - min + 1;
	
	//int *b = (int *)calloc(range, sizeof(int));//����ռ�ͳ�ʼ���ռ�
	int* b = (int *)malloc(sizeof(int)*range);
	memset(b, 0, sizeof(int)*range);
	//ʹ����ʱ�����¼ԭʼ������ÿ�����ĸ���
	for (i = 0; i < len; i++){
		//ע�⣺�����ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�Ų������Խ������
		b[a[i] - min] += 1;
	}
	int j = 0;
	//����ͳ�ƽ�������¶�Ԫ�ؽ��л���
	for (i = 0; i < range; i++){
		while (b[i]--){
			//ע�⣺Ҫ��i��ֵ����min���ܻ�ԭ��ԭʼ����
			a[j++] = i + min;
		}
	}
	//�ͷ���ʱ����
	free(b);
	b = NULL;

}

 void print(int* a, int n)
{
	int i =0;
	for (i; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n", 0);
}
 
 int main()
 {
 	int arr2[] = { 9, 1, 2, 5, 10, 4, 8, 6, 3, 7, 11 };
 	CountSort(arr2,11);
    print(arr2,11);
 	return 0;
 }
