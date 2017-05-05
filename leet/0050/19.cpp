Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int pos = -n;
		for (ListNode *i=head; i!=NULL; i=i->next) { ++pos; }
		ListNode *pre = NULL, *cur = head;
		for (int i=0; i<pos; ++i) {
			pre = cur;
			cur = cur->next;
		}

		if (pre == NULL) {
			head = cur->next;
			delete cur;
		} else {
			pre->next = cur->next;
			delete cur;
		}

		return head;
	}
};
