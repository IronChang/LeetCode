//����ָ����������м�ڵ� 
 struct ListNode 
 {
     int val;
     struct ListNode *next;
 };
 
typedef struct ListNode  List;

struct ListNode* middleNode(struct ListNode* head)
{
	List* slow = head;
	List* fast = head;
	
	while(fast! = NULL && fast->next != NULL)//&& ǰ�������Ϊ����жϺ�������� 
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
}
