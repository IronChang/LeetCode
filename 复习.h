typedef struct Node {
	int val;
	struct Node *next;
}	Node;	// 链表的结点

Node * pushFront(Node *head, int val) {
	// head 表示链表的第一个结点，可能为 NULL
	// 1. 先把 val 装到结点中
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// 2. node 应该成新的第一个结点，所以原来的第一个结点
	// 应该是 node 的下一个结点
	node->next = head;
	// 3. 通知函数的调用者，链表的第一个结点已经发生变了
	// 从原来的 head 变成了 node
	return node;
}

Node * pushBack(Node *head, int val) {
	// 先把 val 装结点
	Node * node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// 因为 node 必然是最后一个结点，所以它的下一个是 NULL
	node->next = NULL;
	// 分情况处理，如果链表不为空
	if (head != NULL) {
		// 先找到当前的最后一个结点
		Node *last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		// last 指向链表的最后一个结点
		// 让 node 成为最后一个结点
		// 也就是上 node 成为 last 的下一个结点
		last->next = node;
		// 链表的第一个结点没有变化
		return head;
	}
	else {
		// 链表为空的情况，node 是插入后链表中唯一的结点
		// node 也就是第一个结点
		return node;
	}
}

// 反转链表
Node * reverseList(Node *head) {
	// 遍历当前链表，不断头插到新链表中
	Node *rHead = NULL;
	// 遍历
	Node *cur = head;
	while (cur != NULL) {
		// 先记录原来的下一个结点
		Node *next = cur->next;
		// 把 cur 头插到 rHead 中
		cur->next = rHead;
		rHead = cur;
		// 让 cur 走到下一个结点上
		cur = next;
	}

	return rHead;
}

// 先删除除了第一个结点外的所有含 val 的结点
// 最后去处理第一个结点
Node * removeAll(Node *head, int val) {
	if (head == NULL) {
		return NULL;
	}
	// 这里对 head 做解引用了，所以必须保证 head 不为 NULL
	Node *cur = head->next;	// 用来遍历的指针，判断是否等于 val
	Node *prev = head;	// 永远指向 cur 的前一个结点，用于删除 cur 结点

	while (cur != NULL) {
		if (cur->val == val) {
			// 需要删除 cur 结点
			prev->next = cur->next;
			// 如果发生了删除，prev 不需要变化，因为 prev 还是 变化后 cur 的前驱
		}
		else {
			// 如果没有删除, prev 和 cur 一起往后走
			prev = cur;
		}

		cur = cur->next;
	}

	if (head->val == val) {
		head = head->next;
	}

	return head;
}

// 合并两个有序链表
// 不断去两个链表中比较，选择较小的结点，尾插到新链表中
Node * mergeOrderedList(Node *head1, Node *head2) {
	if (head1 == NULL) {
		return head2;
	}

	if (head2 == NULL) {
		return head1;
	}

	Node *cur1 = head1;
	Node *cur2 = head2;

	Node *rHead = NULL;		// 新链表的第一个结点
	Node *last = NULL;		// 新链表的最后一个结点

	// 保证两个链表中都还有结点，才比较谁大谁小
	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->val <= cur2->val) {
			// 把 cur1 尾插到新链表
			Node *next = cur1->next;
			// cur1 即将尾插到新链表，所以 cur1 的下一个应该是 NULL
			cur1->next = NULL;
			// 尾插需要分情况处理
			if (rHead == NULL) {
				rHead = cur1;
			}
			else {
				last->next = cur1;
			}
			// 更新新链表的最后一个结点
			last = cur1;

			// 让 cur1 指向第一个链表的下一个结点
			cur1 = next;
		}
		else {
			// 把 cur2 尾插到新链表
			Node *next = cur2->next;
			cur2->next = NULL;
			// 尾插需要分情况处理
			if (rHead == NULL) {
				rHead = cur2;
			}
			else {
				last->next = cur2;
			}
			// 更新新链表的最后一个结点
			last = cur2;

			// 让 cur2 指向第二个链表的下一个结点
			cur2 = next;
		}
	}

	if (cur1 != NULL) {
		last->next = cur1;
	}
	else {
		last->next = cur2;
	}

	return rHead;
}



Node * partition(Node *head, int x) {
	// 遍历 head 所代表的链表，把每个结点的值和 x 进行比较
	// 如果小于 x，尾插到一条小于 x 的链表中
	// 如果大于等于 x，尾插到一条大于等于 x 的链表中

	// 先定义两个变量，代表 小于 x 和 大于等于 x 的链表
	Node * small = NULL;	// 小于 x 的链表
	Node * smallLast = NULL;	// 小于 x 的链表的最后一个结点
	Node * big = NULL;		// 大于等于 x 的链表
	Node * bigLast = NULL;		// 大于等于 x 的链表的最后一个结点

	// 通过 cur 来遍历原链表的每个结点
	Node * cur = head;
	while (cur != NULL) {
		if (cur->val < x) {
			// 把 cur 尾插到 small 中

			/*
			让 cur 的下一个变为 NULL
			cur->next = NULL;
			分情况讨论
			如果 small 所在的链表是空链表			
			if (small == NULL)			
				其实也就是把 cur 头插到 small 所在链表
				让 small 指向 cur 当前指向的结点			
				small = cur;		
			如果 small 所在的链表不是空链表
				先找到 small 链表中的最后一个结点
				1）从第一个结点遍历一直找到最后去
				2）因为之前的最后一个结点是我们插入的，所以我们记录一下即可	【选择】
					smallLast		
				让 smallLast 的下一个结点变成 cur
				smallLast->next = cur;
			记录新的最后一个结点是谁？刚才我们尾插的那个结点 cur
				smallLast = cur;
			最后新的最后一个结点是谁？之前最后一个结点的下一个结点
				smallLast = smallLast->next;
			让 cur 指向原链表的下一个结点
			cur = cur->next;
			Node *next = cur->next;
			尾插
			cur = next;
			*/

			Node *next = cur->next;

			cur->next = NULL;
			if (small == NULL) {
				small = cur;
			}
			else {
				smallLast->next = cur;
			}
			smallLast = cur;

			cur = next;

		}
		else {
			// 把 cur 尾插到 big 中



			Node *next = cur->next;

			cur->next = NULL;
			if (big == NULL) {
				big = cur;
			}
			else {
				bigLast->next = cur;
			}
			bigLast = cur;

			cur = next;
		}
	}

	// 注意：一定要保证最终链表的最后一个结点的下一个是 NULL

	// 如果没有 < x 的链表怎么办？
	if (small == NULL) {
		return big;
	}
	else {
		smallLast->next = big;
		return small;
	}
}

Node * findKthToTail(Node *head, int k) {
	int count = 0;
	for (Node *cur = head; cur != NULL; cur = cur->next) {
		count++;
	}

	if (count < k) {
		return NULL;
	}

	Node *p = head;
	for (int i = 0; i < count - k; i++) {
		p = p->next;
	}

	return p;
}

struct ListNode* middleNode(struct ListNode* head){
	int count = 0;
	for (struct ListNode *cur = head; cur != NULL; cur = cur->next) {
		count++;
	}

	struct ListNode * p = head;
	for (int i = 0; i < count / 2; i++) {
		p = p->next;
	}

	return p;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode *front = pListHead;
	ListNode *back = pListHead;

	//
	for (int i = 0; i < k; i++) {
		if (front == NULL) {
			return NULL;
		}
		front = front->next;
	}

	// front == NULL 表示链表长度就是 k 个
	while (front != NULL) {
		front = front->next;
		back = back->next;
	}

	return back;
}

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}
	ListNode * node = (ListNode *)malloc(sizeof(ListNode));
	node->next = pHead;

	ListNode *prev = node;		// 前驱
	ListNode *p1 = pHead;		// 蓝色
	ListNode *p2 = pHead->next;	// 绿色
	// 永远比较的 p1 和 p2 的 val

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else {
			// 直到 p2 走到尾 或者 不相等
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}

			// 删除 [p1, p2) 的所有结点
			prev->next = p2;

			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;
			}
		}
	}

	return node->next;
}


ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *prev = NULL;		// 前驱
	ListNode *p1 = pHead;		// 蓝色
	ListNode *p2 = pHead->next;	// 绿色
	// 永远比较的 p1 和 p2 的 val
	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else {
			// 直到 p2 走到尾 或者 不相等
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			// 删除 [p1, p2) 的所有结点
			if (prev != NULL) {
				prev->next = p2;
			}
			else {
				pHead = p2;
			}
			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;
			}
		}
	}

	return pHead;
}