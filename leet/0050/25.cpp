#include <cstdlib>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			ListNode *h = NULL, *r = NULL;
			ListNode *th = NULL, *tr = NULL;

			int cnt = k;
			ListNode *cur = head;
			while (cur != NULL) {
				ListNode *nxt = cur->next;
				cur->next = th;
				th = cur;
				tr = (tr == NULL) ? cur : tr;
				cur = nxt;
				if (--k == 0) {
					if (r != NULL) { r->next = th; }
					r = tr;
					h= (h == NULL) ? th : h;
					k = cnt;
					th = tr = NULL;
				}
			}

			ListNode *rv = NULL;
			while (th != NULL) {
				ListNode *tmp = th;
				th = th->next;
				tmp->next = rv;
				rv = tmp;
			}

			if (r == NULL) {
				h = rv;
			} else {
				r->next = rv;
			}

			return h;
		}
};

int main() {
	int n; cin >> n;
	ListNode *head = NULL;
	for (int i=0; i<n; ++i) {
		ListNode *node = new ListNode(n-i);
		node->next = head;
		head = node;
	}
	Solution sol;
	sol.reverseKGroup(head, 2);
	return 0;
}
