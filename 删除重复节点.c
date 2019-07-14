
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){ 
    
    if (pHead == NULL) 
    {
		return NULL;
	}
	
    ListNode *prev = NULL;
    ListNode *cur = pHead;
    ListNode *next = pHead->next;
    
    while(next)
    {
    	if(cur->val != next->val)
		{
			prev = cur;
			cur = cur->next;
			next = next->next;
		} 
		else
		{
			while(next != NULL && next->val == cur->val)
			{
				next = next->next;
			}
			
			if(prev != NULL)
			{
				prev->next = next;
			}
			else
			{
				pHead = next;
			}
			
			while(cur != NULL && cur != next)
			{
				ListNode *p = cur;
				cur = cur->next;
				free(p);	 
			}
			//cur = next;
			
			if(next != NULL)
			{
				next = next->next;
			}
		}
	}
	return pHead;
}; 
