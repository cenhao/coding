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
    ListNode* middleNode(ListNode* head) {
		if (head == nullptr) { return nullptr; }
		int len = 0;
		for (auto *p=head; p!=nullptr; p=p->next) { ++len; }
		len >>= 1;
		ListNode *ans = head;
		for (int i=0; i<len; ++i) { ans = ans->next; }
		return ans;
    }
};
