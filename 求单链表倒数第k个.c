/*
��Ŀ����һ����������д����������k���ڵ㡮
˼·������ָ��
*/

void reverse_k(struct ListNode *ptl, int k)
{
	assert(ptl);
	struct ListNode *cur;
	struct ListNode *prev;
	ptl = cur = prev;
	while (k--)
	{
		cur = cur->next;
	}

	while (cur)
	{
		cur = cur->next;
		prev = prev->next;
	}


	printf("%d\n", prev->val);
}


int main()
{

	system("pause");
	return 0;
}
