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
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		ListNode *cur = root, *tmp;
		int cnt = 0;
		while (cur != nullptr) {
			++cnt;
			cur = cur->next;
		}

		int avg = cnt / k;
		int rmd = cnt % k;

		vector<ListNode*> ans;

		tmp = cur = root;
		int kcnt = 0;
		cnt = 0;
		while (kcnt < k) {
			++cnt;
			ListNode *ttmp = tmp;
			if (tmp != nullptr) { tmp = tmp->next; }

			if (cnt >= avg + ((kcnt < rmd) ? 1 : 0)) {
				if (ttmp != nullptr) { ttmp->next = nullptr; }
				++kcnt;
				ans.push_back(cur);
				cur = tmp;
				cnt = 0;
			}


		}

		return ans;
	}
};
