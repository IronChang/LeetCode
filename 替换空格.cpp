/*
题目：将字符串中的空格替换为%20，
思路：要在字符数组中间加上%20，首先要定义两个数组arr和arr2,arr1用来存放原字符，而arr2用来存放加完%20?之后的字符
接下来就是函数的实现了：
当arr不为0时，进入while循环，
如果arr不是空格时，那么就将arr1的拷贝给arr2，
如果遇到空格的时候，就要在arr2后面加上%20?，而arr2就向后面移动三个位置

*/

int Tihuan(char *s1,char *s2)
{
	while (*s1)
	{
		if (*s1 != ' ')
		{
			*s2 = *s1;
			s2++;
		}
		else
		{
			strcpy(s2, "%20");
			s2 += 3;
		}
		s1++;
	}
	*s2 = '\0';
	return 0;
}

int main()
{
	char s1[] = { "abc defgx yz" };
	char s2[50];
	Tihuan(s1, s2);
	printf("%s\n", s2);
	system("pause");
	return 0;
}
