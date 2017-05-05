class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		ListNode *h1 = l1, *h2 = l2, *rear = head;
		while (h1 != NULL && h2 != NULL) {
			if (h1->val < h2->val) {
				rear->next = h1;
				rear = rear->next;
				h1 = h1->next;
			} else {
				rear->next = h2;
				rear = rear->next;
				h2 = h2->next;
			}
		}

		while (h1 != NULL) {
			rear->next = h1;
			rear = rear->next;
			h1 = h1->next;
		}
		while (h2 != NULL) {
			rear->next = h2;
			rear = rear->next;
			h2 = h2->next;
		}
		rear = head;
		head = head->next;
		delete rear;
		return head;
	}
};
