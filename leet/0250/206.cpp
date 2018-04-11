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
    ListNode* reverseList(ListNode* head) {
		ListNode *cur = nullptr, *nxt = head; 
		while (nxt != nullptr) {
			ListNode *tmp = nxt->next;
			nxt->next = cur;
			cur = nxt;
			nxt = tmp;
		}

		return cur;
    }
};
