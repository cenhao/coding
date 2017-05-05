class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL) { return head; }

		ListNode *pre = new ListNode(0), *ret;
		pre->next = head; ret = pre;
		for (ListNode *cur=head, *adj=NULL, *next=NULL; cur!=NULL; cur=next) {
			adj = cur->next;
			next = NULL;
			if (adj != NULL) {
				next = adj->next;

				pre->next = adj;
				adj->next = cur;
				cur->next = next;
				pre = cur;

				if (cur == head) { ret->next = adj; }
			}
		}

		pre = ret; ret = ret->next; delete pre;
		return ret;
	}
};
