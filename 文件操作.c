//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "w");
//
//	//fwrite(&a, 4, 1, pf);
//	fputs("hello world", pf);
//	fclose(pf);
//
//	pf = fopen("abc.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//
//	pf = NULL;
//	
//	system("pause");
//	return 0;
//
//}


//int main()
//{
//	FILE* pf;
//	pf = fopen("wxam.txt", "w");
//	fputs("this is an apple", pf);
//	fseek(pf, 9, SEEK_SET);
//	fputs(" sam", pf);
//	fclose(pf);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int n;
//	FILE * pf;
//	char buff[27];
//	pf = fopen("myfile.txt", "w+");
//
//	for (n = 'A'; n <= 'Z'; n++)
//	{
//		fputc(n, pf);
//	}
//	rewind(pf);
//	fread(buff, 1, 26, pf);
//	fclose(pf);
//	buff[26] = '\0';
//	puts(buff);
//
//	system("pause");
//	return 0;
//
//}


enum { SIZE = 5 };
int main(void)
{
	double a[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double b = 0.0;
	size_t ret_code = 0;
	FILE *fp = fopen("test.bin", "wb"); // 必须用二进制模式
	fwrite(a, sizeof(*a), SIZE, fp); // 写 double 的数组
	fclose(fp);
	fp = fopen("test.bin", "rb");
	// 读 double 的数组
	while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
	{
		printf("%lf\n", b);
	}
	if (feof(fp))
		printf("Error reading test.bin: unexpected end of file\n");
	else if (ferror(fp)) {
		perror("Error reading test.bin");
	}
	fclose(fp);
	fp = NULL;

system("pause");
  return 0;
}
