/*
��Ŀ�����ַ����еĿո��滻Ϊ%20��
˼·��Ҫ���ַ������м����%20������Ҫ������������arr��arr2,arr1�������ԭ�ַ�����arr2������ż���%20?֮����ַ�
���������Ǻ�����ʵ���ˣ�
��arr��Ϊ0ʱ������whileѭ����
���arr���ǿո�ʱ����ô�ͽ�arr1�Ŀ�����arr2��
��������ո��ʱ�򣬾�Ҫ��arr2�������%20?����arr2��������ƶ�����λ��

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
