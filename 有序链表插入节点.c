//���������в���һ�����ݣ���������������Բ��� 
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
