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
    vector<int> nextLargerNodes(ListNode* head) {
		vector<int> ans;
		auto cmp = [](pair<int, int> &p1, pair<int, int> &p2) { return p1.first > p2.first; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>  pq(cmp);
		for (auto *p=head; p!=nullptr; p=p->next) {
			while (!pq.empty() && pq.top().first<p->val) {
				ans[pq.top().second] = p->val;
				pq.pop();
			}
			pq.push(make_pair(p->val, int(ans.size())));
			ans.push_back(0);
		}
		return ans;
    }
};
