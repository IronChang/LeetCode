 struct ListNode
 {
     int val;
     struct ListNode *next;
 };



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct SlistNode *new_head,*cur;
	new_head = cur = (struct ListNode*)malloc(sizeof(struct ListNode*));

	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}

	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			cur->next=l1;
			cur=cur->next;
			l1=l1->next; 
		}
		else
		{
			cur->next=l2;
			cur=cur->next;
			l2=l2->next; 	
		}
	}

}

