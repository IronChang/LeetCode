
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        
        if(pHead == NULL)
        {
        	return NULL;
		}
		 else if(pHead->next == NULL)
		{
			return pHead;
		}
        ListNode *ListA,*curA;
        ListNode *ListB,*curB;
        ListNode *cur = pHead;
        ListA = curA = (ListNode*)malloc(sizeof(ListNode));
        ListB = curB = (ListNode*)malloc(sizeof(ListNode));
        
        while(cur)
        {
        	if(cur->val < x)
        	{
        		curA->next = cur;
        		curA = curA->next;
			}
			else
			{
				curB->next = cur;
				curB = curB->next;
			}
			cur = cur->next;	
		}
		
		curA->next = ListB->next;
		curB->next = NULL;			
		pHead = ListA->next;
		
		return pHead;
		
    }
};
