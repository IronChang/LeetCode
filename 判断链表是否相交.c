/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
     struct ListNode *Acur = headA,*Bcur = headB;
	 int lenA = 0, lenB = 0;
	 
	 //计算出量表A,B的长度 
	 while(Acur)
	 {
	 	++lenA;
	 	Acur = Acur->next;
	 }
	 
	 while(Bcur)
	 {
	 	++lenB;
	 	Bcur = Bcur->next;
	 } 
	 
	if(Acur != Bcur)
    {
        return NULL;
    }
	 
    struct ListNode *shortList = headA;
	struct ListNode *longList = headB;
	 if(lenA > lenB)
	 {
	 	shortList = headB;
	 	longList = headA;
	 } 
	 
	 int gsp = abs(lenA-lenB);//计算出两个长度差的绝对值 
	 
	 while(gsp--)//将较长的链表 
	 {
	 	longList = longList->next;
	 }
	 
	 while(longList != shortList)
	 {
	 	longList = longList->next;
	 	shortList = shortList->next;
	 }
	 
	 return shortList;
}
