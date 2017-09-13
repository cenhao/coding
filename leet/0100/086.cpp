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
	ListNode* partition(ListNode* head, int x) {
		ListNode s(0), b(0);
		ListNode *pst = &s, *pbt = &b;

		for (ListNode *cur=head; cur!=nullptr; cur=cur->next) {
			if (cur->val < x) {
				pst = pst->next = cur;
			} else {
				pbt = pbt->next = cur;
			}
		}

		pbt->next = nullptr;
		pst->next = b.next;
		return s.next;
	}
};
