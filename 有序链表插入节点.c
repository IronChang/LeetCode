//有序链表中插入一个数据，插入后链表有序性不变 
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}ListNode;

void InsertDateSet(ListNode *head,ListNode *s)
{
	ListNode *p = head;
	
	while(p->next != NULL&&p->val < s->val)
	{
		p = p->next;
	} 
	
	s->next = p->next;
	p->next = s;
} 
