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
    ListNode* insertionSortList(ListNode* head) {
		ListNode vh(0);
		while (head != nullptr) {
			ListNode *tmp = head->next;
			ListNode *pre = &vh, *cur = vh.next;
			while (cur != nullptr && head->val > cur->val) {
				pre = cur;
				cur = cur->next;
			}
			pre->next = head;
			head->next = cur;
			head = tmp;
		}

		return vh.next;
    }
};
