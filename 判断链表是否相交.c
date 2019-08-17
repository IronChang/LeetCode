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
	 
	 //���������A,B�ĳ��� 
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
	 
	 int gsp = abs(lenA-lenB);//������������Ȳ�ľ���ֵ 
	 
	 while(gsp--)//���ϳ������� 
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
