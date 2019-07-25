1.https://leetcode-cn.com/problems/remove-linked-list-elements/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
        return NULL;
    
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    
    while(cur)
    {
        if(cur->val == val)
        {
            struct ListNode* next = cur->next;
            if(prev == NULL)
            {
                head = cur->next;
            }
            else
            {
                prev->next = cur->next;  
            }
            
            free(cur);
            cur = next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    
    return head;
}


2.
https://leetcode-cn.com/problems/reverse-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // 三个指针翻转的思想完成逆置
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* n1, *n2, *n3;
    n1 = head;
    n2 = n1->next;
    n3 = n2->next;
    n1->next = NULL;
    while(n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if(n3)
            n3 = n3->next;
    }
    
    return n1;
}

或
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 取节点头插的思想完成逆置
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while(cur)
    {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    
    return newhead;
}

3.
https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

4.
https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        struct ListNode* slow = pListHead;
        struct ListNode* fast = slow;
        while(k--)
        {
            if(fast)
                fast = fast->next;
            else
                return NULL;
        }
        
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

5.https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    
    // 先取一个小的节点做头
    struct ListNode* head, *tail;
    if(l1->val < l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    
    // 取小的节点进行尾插
    tail = head;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    if(l1 != NULL)
        tail->next = l1;
    
    if(l2 != NULL)
        tail->next = l2;
    
    return head;
}

6.
https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead == NULL)
            return NULL;
        
        struct ListNode* lessHead, *lessTail,*greaterHead, *greaterTail;
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* cur = pHead;
        while(cur)
        {
            if(cur->val < x)
            {
                lessTail->next = cur;
                lessTail = lessTail->next;
            }
            else
            {
                greaterTail->next = cur;
                greaterTail = greaterTail->next;
            }
            cur = cur->next;
        }
        
        lessTail->next = greaterHead->next;
        greaterTail->next = NULL;
        
        pHead = lessHead->next;
        free(lessHead);
        free(greaterHead);
        
        return pHead;
    }
};


7.
https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&&tqId=11209&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        
        struct ListNode* n0 = NULL;
        struct ListNode* n1 = pHead;
        struct ListNode* n2 = n1->next;
        while(n2 != NULL)
        {
            if(n1->val != n2->val)
            {
                n0 = n1;
                n1 = n2;
                n2 = n2->next;
            }
            else
            {
				// n2去找第一个不相同的节点
                while(n2 && n2->val == n1->val)
                {
                    n2 = n2->next;
                }
                
                if(n0)
                    n0->next = n2;
                else
                    pHead = n2;
                
                // 删除掉重复的节点
                while(n1 != n2)
                {
                    struct ListNode* next = n1->next;
                    free(n1);
                    n1 = next;
                }
                
                n1 = n2;
                if(n2)
                    n2 = n2->next;
            }
        }
        
        return pHead;
    }
};

8.
https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    struct ListNode* reverseList(struct ListNode* head) {
        struct ListNode* newhead = NULL;
        struct ListNode* cur = head;
        while(cur)
        {
            struct ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
     
        return newhead;
    }
     
    bool chkPalindrome(ListNode* A) {
        int n = 0;
        struct ListNode* cur = A;
        while(cur)
        {
            cur = cur->next;
            ++n;
        }
         
        cur = A;
        int mid = n/2;
        while(mid--)
        {
            cur = cur->next;
        }
         
        struct ListNode* head1 = A;
        struct ListNode* head2 = reverseList(cur);
         
        mid = n/2;
        while(mid--)
        {
            if(head1->val == head2->val)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            else
            {
                   return false;
            }
        }
         
        return true;
    }
};

或

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        int a[900];
        int n = 0;
        struct ListNode* cur = A;
        while(cur)
        {
            a[n++] = cur->val;
            cur = cur->next;
        }
        
        int left = 0, right = n-1;	
        while(left < right)
        {
              if(a[left] != a[right])
                  return false;
            ++left;
            --right;
        }
        
        return true;
    }
};

9.https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0;
    struct ListNode* curA = headA, *curB = headB;
    while(curA) {
        ++lenA;
        curA = curA->next;
    }
    
    while(curB) {
        ++lenB;
        curB = curB->next;
    }
    
    int gap = abs(lenA-lenB);
    struct ListNode* longList = headA, *shortList = headB;
    if(lenA < lenB) {
        longList = headB;
        shortList = headA;
    }
    
    while(gap--){
        longList = longList->next;
    }
    
    while(longList && shortList)
    {
        if(longList->val == shortList->val) {
            return longList;
        }
        else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    
    return NULL;
}

10.
https://leetcode-cn.com/problems/linked-list-cycle/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
   struct ListNode* slow = head;
   struct ListNode* fast = head;
   while(fast && fast->next)
   {
       slow = slow->next;
       fast = fast->next->next;
       
       if(slow == fast)
           return true;
   }
    
    return false;
}

问题：请证明为什么是slow走一步，fast走两步？slow走一步，fast走三步行不行？四步？

12
https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    // 1.复制节点
    struct RandomListNode* cur = head;
    while(cur)
    {
        struct RandomListNode* next = cur->next;
        struct RandomListNode* copy = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
        copy->label = cur->label;
        copy->next = NULL;
        cur->next = copy;
        copy->next = next;
        
        cur = next;
    }
    
    // 2.置复制节点的random
    cur = head;
    while(cur)
    {
        struct RandomListNode* copy = cur->next;
        if(cur->random)
            copy->random = cur->random->next;
        else
            copy->random = NULL;
        
        cur = copy->next;
    }
        
    // 3.拆解链表
    struct RandomListNode* newhead= NULL, *newtail = NULL;
    cur = head;
    while(cur)
    {
        struct RandomListNode* copy = cur->next;
        struct RandomListNode* next = copy->next;
        
        if(newtail == NULL)
        {
            newhead = newtail = copy;
        }
        else
        {
            newtail->next = copy;
            newtail = newtail->next;
        }
         
        cur->next = next;
        
        cur = next;
    }
    
    return newhead;   
}
