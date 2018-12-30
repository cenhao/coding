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
    ListNode* removeElements(ListNode* head, int val) {
		ListNode h(0);
		h.next = head;
		for (ListNode *pre=&h, *cur=h.next; cur!=nullptr; pre=cur, cur=cur->next) {
			if (cur->val != val) { continue; }
			auto *tmp = cur;
			pre->next = cur->next;
			cur = pre;
			delete tmp;
		}

		return h.next;
    }
};
