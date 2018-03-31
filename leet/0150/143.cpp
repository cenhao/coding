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
    void reorderList(ListNode* head) {
		if (head == nullptr) { return; }
        ListNode *cur = head, *pre, vh(0);
        int cnt = 0;
        while (cur != nullptr) {
            ++cnt;
            cur = cur->next;
        }   

        int half = (cnt+1) >> 1;
        cur = head;
        for (int i=0; i<half; ++i) {
            pre = cur;
            cur = cur->next;
        }   

        pre->next = nullptr;

        while (cur != nullptr) {
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = vh.next;
            vh.next = tmp;
        }   

        cur = head;
        while (vh.next != nullptr) {
            ListNode *tmp = vh.next;
            vh.next = tmp->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }   
    }   
};

