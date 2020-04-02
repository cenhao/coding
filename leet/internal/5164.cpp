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
	ListNode* dfs(ListNode *cur) {
		if (cur == nullptr) { return cur; }
		cur->next = dfs(cur->next);
		int sm = 0;
		for (auto *ptr=cur; ptr!=nullptr; ptr=ptr->next) {
			sm += ptr->val;
			if (sm == 0) { return ptr->next; }
		}

		return cur;
	}
    ListNode* removeZeroSumSublists(ListNode* head) {
		return dfs(head);
    }
};
