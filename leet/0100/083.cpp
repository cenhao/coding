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
		ListNode *tmp = &h;
		bool is_init = true;
		for (ListNode *cur=head; cur!=nullptr; cur=cur->next) {
			if (is_init || cur->val != tmp->val) {
				is_init = false;
				tmp = tmp->next = cur;
			}
		}

		tmp->next = nullptr;
		return h.next;
	}
};
