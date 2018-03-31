/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void append(ListNode *&h, ListNode *&r, ListNode *picked) {
		if (h == nullptr) {
			h = r = picked;
		} else {
			r->next = picked;
			r = picked;
		}
	}

    ListNode* sortList(ListNode* head) {
		int tot = 0;
		for (ListNode *cur=head; cur!=nullptr; cur=cur->next) { ++tot; }
		for (int i=1; (1<<(i-1))<=tot; ++i) {
			int len = 1 << i, half = 1 << (i-1);
			ListNode *gptr = head, *gh = nullptr, *gr = nullptr;
			while (gptr != nullptr) {
				ListNode *lptr = gptr;
				for (int j=0; j<half && gptr!=nullptr; ++j) { gptr = gptr->next; }
				ListNode *rptr = gptr, *lend = gptr;
				for (int j=0; j<half && gptr!=nullptr; ++j) { gptr = gptr->next; }
				ListNode *rend = gptr, *h = nullptr, *r = nullptr;
				while (lptr!=lend && rptr!=rend) {
					ListNode *picked;
					if (lptr->val < rptr->val) {
						picked = lptr;
						lptr = lptr->next;
					} else {
						picked = rptr;
						rptr = rptr->next;
					}
					append(h, r, picked);
				}

				while (lptr != lend) {
					append(h, r, lptr);
					lptr = lptr->next;
				}

				while (rptr != rend) {
					append(h, r, rptr);
					rptr = rptr->next;
				}

				if (r != nullptr) { r->next = nullptr; }
				if (gh == nullptr) {
					gh = h; gr = r;
				} else {
					gr->next = h;
					gr = r;
				}
			}

			head = gh;
		}

		return head;
    }
};
