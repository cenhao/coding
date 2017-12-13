/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		vector<int> tmp;
		bool nxt = false, forward = true;
		queue<TreeNode*> q;
		q.push(nullptr);
		if (root != nullptr) { q.push(root); }
		int sz, cnt;

		while (!q.empty()) {
			TreeNode *t = q.front(); q.pop();
			if (t == nullptr) {
				if (tmp.size() > 0) {
					ans.push_back(move(tmp));
					forward = !forward;
				}
				nxt = true;
				tmp.resize(sz = q.size());
				cnt = 0;
				continue;
			}

			if (nxt) {
				nxt = false;
				q.push(nullptr);
			}

			if (forward) {
				tmp[cnt++] = t->val;
			} else {
				tmp[sz-cnt-1] = t->val;
				++cnt;
			}

			if (t->left != nullptr) { q.push(t->left); }
			if (t->right != nullptr) { q.push(t->right); }
		}

		return ans;
	}
};
