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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) { return ans; }
		queue<TreeNode*> q;
		q.push(nullptr);
		q.push(root);
		bool first;
		int cnt;
		vector<int> lvl;

		while (!q.empty()) {
			TreeNode *tmp = q.front(); q.pop();
			if (tmp == nullptr) {
				first = true;
				cnt = 0;
				if (lvl.size() > 0) { ans.push_back(move(lvl)); }
				lvl.resize(q.size());
				continue;
			}

			lvl[cnt++] = tmp->val;
			if (first) {
				first = false;
				q.push(nullptr);
			}
			if (tmp->left != nullptr) { q.push(tmp->left); }
			if (tmp->right != nullptr) { q.push(tmp->right); }
		}

		reverse(ans.begin(), ans.end());
		return ans;
    }
};
