/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode* Phead,*cur;
        Phead = (struct ListNode*)malloc(sizeof(struct ListNode));
        Phead->next = nullptr;
		cur = Phead;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				cur->next = l2;
				l2 = l2->next;
				cur = cur->next;
			}
			else
			{
				cur->next = l1;
				l1 = l1->next;
				cur = cur->next;
			}
		}

		if (l1 == nullptr)
		{
			cur->next = l2;
		}

		if (l2 == nullptr)
		{
			cur->next = l1;
		}

		return Phead->next;
	}
};
