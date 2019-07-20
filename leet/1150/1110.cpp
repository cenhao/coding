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
	bool traverse(TreeNode *cur, unordered_set<int> &hs, vector<TreeNode*> &ans, TreeNode *p) {
		if (cur == nullptr) { return false; }
		if (hs.find(cur->val) != hs.end()) {
			traverse(cur->left, hs, ans, nullptr);
			traverse(cur->right, hs, ans, nullptr);
			return true;
		}

		if (p == nullptr) { ans.emplace_back(cur); }
		if (traverse(cur->left, hs, ans, cur)) { cur->left = nullptr; }
		if (traverse(cur->right, hs, ans, cur)) { cur->right = nullptr; }
		return false;
	}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> hs(to_delete.begin(), to_delete.end());
		vector<TreeNode*> ans;
		traverse(root, hs, ans, nullptr);
		return move(ans);
    }
};

