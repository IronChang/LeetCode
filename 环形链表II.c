
 struct ListNode {
     int val;
     struct ListNode *next;
 };

//���ÿ���ָ���������Ƿ��л�
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *slow = head;
	struct ListNode *fast = head;
    struct ListNode *temp = NULL;
	
	while(fast && fast->next)//�ж������Ƿ��л������Ҽ�¼����ָ��������ͷ��temp
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
		{ 
            temp = slow;
            break;
		}
	} 
    
    if(temp == NULL)//���û�л�������NULL
    {
        return NULL;
    }
    
    slow = head;
    
    while(slow != temp)//������ͷ��ָ��tempͬʱ�ߣ����ʱ���ǻ���ʼ��λ��
    {
        slow = slow->next;
        temp = temp->next;
    }
    
	return temp;
}
