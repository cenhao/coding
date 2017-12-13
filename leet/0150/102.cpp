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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		vector<int> tmp;
		queue<TreeNode*> q;
		q.push(nullptr);
		q.push(root);
		bool nxt = false;

		while (!q.empty()) {
			TreeNode *t = q.front(); q.pop();
			if (t == nullptr) {
				if (tmp.size() > 0) { ans.push_back(move(tmp)); }
				nxt = true;
				continue;
			}
			tmp.push_back(t->val);
			if (nxt) {
				nxt = false;
				q.push(nullptr);
			}
			if (t->left != nullptr) { q.push(t->left); }
			if (t->right != nullptr) { q.push(t->right); }
		}

		return ans;
	}
};
