struct ListNode
{
	int val;
	struct ListNode *next;
};



struct ListNode* reverseList(struct ListNode* head)
{
	assert(head);
	struct ListNode *new_head = NULL, *next;
	while (head)
	{
		next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
	}
	return new_head;

}
