struct  ListNode
{
    int val;
	struct ListNode *next;	
};
//ɾ�������еĽڵ���Ҫ֪���ýڵ��ǰ���ͺ�� 
struct ListNode* removeElements(struct* head,int val)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	
	while(cur != NULL)
	{
		if(cur->val = val)
		{
			if(prev == NULL)//�жϸýڵ���û��ǰ�� 
			{
				head = cur->next;
				free(cur);
				cur = head; 
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	} 
}
