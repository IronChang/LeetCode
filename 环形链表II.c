
 struct ListNode {
     int val;
     struct ListNode *next;
 };

//利用快慢指针解决链表是否有环
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *slow = head;
	struct ListNode *fast = head;
    struct ListNode *temp = NULL;
	
	while(fast && fast->next)//判断链表是否有环，并且记录快慢指针相链表头和temp
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
		{ 
            temp = slow;
            break;
		}
	} 
    
    if(temp == NULL)//如果没有环，返回NULL
    {
        return NULL;
    }
    
    slow = head;
    
    while(slow != temp)//从链表头和指针temp同时走，相等时则是环开始的位置
    {
        slow = slow->next;
        temp = temp->next;
    }
    
	return temp;
}
