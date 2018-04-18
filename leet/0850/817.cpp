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
    int numComponents(ListNode* head, vector<int>& G) {
		unordered_set<int> hs(G.begin(), G.end());
		int cnt = 0, ans = 0;
		for (ListNode *ptr=head; ptr!=nullptr; ptr=ptr->next) {
			if (hs.find(ptr->val) == hs.end()) {
				ans += (cnt == 0) ? 0 : 1;
				cnt = 0;
			} else {
				++cnt;
			}
		}
		ans += (cnt == 0) ? 0 : 1;
		return ans;
    }
};
