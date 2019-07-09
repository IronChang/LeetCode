struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    
    struct ListNode *new_head = NULL, *_next;
	while (head)
	{
	  _next = head->next;
	  head->next = new_head;
	  new_head = head;
	  head = _next; 
	}
	return new_head;
} 
