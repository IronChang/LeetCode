
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class PalindromeList {
public:
    bool chkPalindrome(ListNode* A)
    {
        int a[10000];
        int i=0;
        ListNode* p=A;
        while(p)
        {
            a[i++]=p->val;
            p=p->next;
        }
 
        int k=0;
        for (int j=i-1;j>=i/2;j--)
        {
            if (a[j]==a[k++])
                continue;
            else
                return false;
        }
        return true;
 
    }
};
