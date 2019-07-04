/*使其可以删除某个链表中给定的（非末尾）节点，
你将只被给定要求被删除的节点。/
 struct ListNode 
 {
     int val;
     struct ListNode *next;
 };

void deleteNode(struct ListNode* node) 
{
    
    *node=*(node->next);
    
}
