  struct ListNode 
  {
      int val;
      struct ListNode *next;
  };
struct ListNode* middleNode(struct ListNode* head)
{
	int count=0;
	struct ListNode *mid=head;
	
	while(mid!=NULL)
	{
		++count;
		mid=mid->next;
	}
	
    mid=head;
    int n=count/2;
    
    while(n--)
    {
    	mid=mid->next;
	}
	
	if((count%2)==0)
	{
		head=mid;
	}
	else
	{
		head=mid;
	}
	
	return head;
}
