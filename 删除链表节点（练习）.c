struct  ListNode
{
    int val;
	struct ListNode *next;	
};
//删除链表中的节点需要知道该节点的前驱和后继 
struct ListNode* removeElements(struct* head,int val)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	
	while(cur != NULL)
	{
		if(cur->val = val)
		{
			if(prev == NULL)//判断该节点有没有前驱 
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
