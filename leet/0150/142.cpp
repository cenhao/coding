/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Let's assume the size of the loop is r, and the fast and slow
// meet after k step.
//
// For fast, it walked 2k steps.
//
// 0 - 1 - 2 - 3 ... i ... k ... n
//                   ^           |
//                   +-----------+
// here, i...n is r.
// Since we can think of fast as taking 2k steps,
// it's easy to tell i .. n is r, and k % r == 0
//
// Let's say k-i = b, we have i + b = k = q*r.
//
// start from k, if we walk i steps, we will return to i,
// because i = k - b = q*r - b, that's like reversing b steps from where
// fast and slow meet.
//
// Because we don't know the value of b, but we can start from head and
// continue walking, until the two pointer meet.
//
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;

		while (fast != nullptr) {
			slow = slow->next;
			fast = (fast->next == nullptr) ? fast->next : fast->next->next;
			if (fast == slow) { break; }
		}

		if (fast == nullptr) { return nullptr; }
		fast = head;
		while (fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
    }
};
