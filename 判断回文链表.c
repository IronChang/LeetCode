//struct ListNode {
   // int val;
  //  struct ListNode *next;
  //  ListNode(int x) : val(x), next(NULL) {}
//};

class PalindromeList {
public:
	
ListNode* reverseList(ListNode* head)
{
	ListNode *new_head = NULL, *next;
	while (head)
	{
		next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
	}
	return new_head;
}
    
bool chkPalindrome(ListNode* A)
{
	ListNode* cur = A;
	int a[900] = {0};
	int n = 0;
	inr i = 0;
	while(cur != NULL)
	{
		a[i++] = cur->val;
		n++;
		cur = cur->next;
	}
	
	int left = 0,right = n-1;
	
	while(left<right)
	{
		if(a[left] != a[right])
		{
			return false;
		}
		
		++left;
		--right;
	}
	return true;
}
};
