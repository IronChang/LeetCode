typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* reverse(ListNode* head)
{
	ListNode *prev,*cur;
	prev = NULL;
	
	while(cur != NULL)
	{
		cur = head->next;
		head->next = prev;
		prev = head;
		head = cur;

	}
}
