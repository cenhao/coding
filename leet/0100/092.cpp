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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode pseudo(0);
		pseudo.next = head;
		ListNode *p = &pseudo, *cur = head, *h, *t;

		for (int i=1; i<=n; ++i) {
			if (i <= m) {
				h = p;
				t = p = cur;
				cur = cur->next;
			} else {
				t->next = cur->next;
				cur->next = h->next;
				h->next = cur;
				cur = t->next;
			}
		}

		return pseudo.next;
    }
};
