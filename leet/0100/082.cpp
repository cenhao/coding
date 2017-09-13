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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode h(0);
		ListNode *tmp = new ListNode(0), *t = &h;
		bool is_init = true;
		int last, cnt;
		for (ListNode *cur=head; cur!=nullptr; cur=cur->next) {
			if (is_init || tmp->val != cur->val) {
				if (is_init || cnt > 1) {
					tmp->val = cur->val;
				} else {
					t = t->next = tmp;
					tmp = new ListNode(cur->val);
				}

				cnt = 1;
				is_init = false;
			} else {
				++cnt;
			}
		}

		if (cnt == 1) {
			t->next = tmp;
		} else {
			delete tmp;
		}

		return h.next;
	}
};
