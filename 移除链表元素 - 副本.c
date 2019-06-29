/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){

        struct ListNode* prev = NULL;
		struct ListNode* cur = head;
        
        while (cur != NULL)
		{
			if (cur->val == val)
			{
				if (prev == NULL)//该节点没有前驱
				{
					head= cur->next;
                    free(cur);
                    cur=head;
				}
				else//该节点有前驱
				{
					prev->next = cur->next;
                    free(cur);
                    cur=NULL;
                    cur = prev->next;
				}
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
			
		}
       return head;
    }

