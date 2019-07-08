//快慢指针输出链表中间节点 
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
	
	while(fast! = NULL && fast->next != NULL)//&& 前面的条件为真才判断后面的条件 
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
}
