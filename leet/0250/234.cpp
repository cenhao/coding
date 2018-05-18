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
    bool isPalindrome(ListNode* head) {
		int len = 0;
		for (auto *ptr=head; ptr!=nullptr; ptr=ptr->next) {
			++len;
		}
		if (len <= 1) { return true; }
		int half = (len+1) / 2;
		auto *hptr = head;
		for (int i=0; i<half; ++i) {
			hptr = hptr->next;
		}
		ListNode *pre = nullptr;
		while (hptr != nullptr) {
			auto *nxt = hptr->next;
			hptr->next = pre;
			pre = hptr;
			hptr = nxt;
		}
		for (auto *bptr=pre, *fptr=head; bptr!=nullptr; bptr=bptr->next, fptr=fptr->next) {
			if (bptr->val != fptr->val) { return false; }
		}
		return true;
    }
};
