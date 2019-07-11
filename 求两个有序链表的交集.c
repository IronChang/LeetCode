//两个递增链表求交集 
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}ListNode;

void Intersection(ListNode *LA,ListNode *LB,ListNode *LC)
{
	ListNode *pa,*pb,*pc,q;
	pa = LA;
	pb = LB;
	pc = LC;
	
	while(pa != NULL && pb != NULL)
	{
		if(pa->val < pb->val)
		{
			pa = pa->next;
		}
		else if(pa->val > pb->val)
		{
			pb = pb->next;
		}
		else
		{
			p = (ListNode*)malloc(sizeof(ListNode));
			q->val = pa->val;
			pc->next = q;
			pc = q;
			pa = pa->next;
			pb = pb->next; 
		}
	} 
	pc->next = NULL;
} 
