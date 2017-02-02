#include <cstdlib>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
	bool hasCycle(ListNode *head) {
		if (head == NULL) { return false; }

		ListNode *fast = head->next, *slow = head;
		fast = (fast == NULL) ? NULL : fast->next;

		while (slow != fast) {
			slow = slow->next;
			if (fast != NULL) { fast = fast->next; }
			if (fast != NULL) { fast = fast->next; }
		}

		return slow != NULL;
	}
};

int main() {
	ListNode node(1);
	Solution sol;
	sol.hasCycle(&node);
	return 0;
}
