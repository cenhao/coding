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
    ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr) { return head; }
		int len = 0;
		ListNode *cur = head, *last, *ret;
		while (cur != nullptr) {
			++len;
			last = cur;
			cur = cur->next;
		}

		k = len - (k % len);
		last->next = head;
		for (cur=head; k>1; --k) { cur = cur->next; }
		ret = cur->next;
		cur->next = nullptr;
		return ret;
    }
};
