/*ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㣬
�㽫ֻ������Ҫ��ɾ���Ľڵ㡣/
 struct ListNode 
 {
     int val;
     struct ListNode *next;
 };

void deleteNode(struct ListNode* node) 
{
    
    *node=*(node->next);
    
}
