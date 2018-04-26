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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr) { return nullptr; }
		auto *tmp_a = headA, *tmp_b = headB;
		int acnt = 1, bcnt = 1;
		while (tmp_a->next != nullptr) {
			tmp_a = tmp_a->next;
			++acnt;
		}
		while (tmp_b->next != nullptr) {
			tmp_b = tmp_b->next;
			++bcnt;
		}
		if (tmp_a != tmp_b) { return nullptr; }
		tmp_a = headA; tmp_b = headB;
		while (acnt > bcnt) {
			--acnt;
			tmp_a = tmp_a->next;
		}
		while (bcnt > acnt) {
			--bcnt;
			tmp_b = tmp_b->next;
		}
		while (tmp_a != tmp_b) {
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		return tmp_a;
    }
};
