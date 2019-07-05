	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead==NULL||k==0)
		{
			return NULL;
		} 	
       ListNode *prev,*cur;
       cur= pListHead;

	  for(unsigned int i=0;i<k-1;i++)
	  {
	  	if(cur->next!=NULL)
	  	{
	  		cur=cur->next;
		}
		else
		{
			return NULL;
		}
	  }
	  prev=pListHead;
	  while(cur->next!=NULL)
	  {
	  	prev=prev->next;
	  	cur=cur->next;
	  }
	  return prev;
    }
};
