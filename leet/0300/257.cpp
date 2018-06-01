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
	void traverse(TreeNode *cur, string s, vector<string> &ans) {
		if (s.length() != 0) { s += "->"; }
		s += to_string(cur->val);
		if (cur->left==cur->right && cur->left==nullptr) {
			ans.emplace_back(move(s));
			return;
		}
		if (cur->left != nullptr) { traverse(cur->left, s, ans); }
		if (cur->right != nullptr) { traverse(cur->right, s, ans); }
	}
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;
		if (root == nullptr) { return ans; }
		traverse(root, "", ans);
		return ans;
    }
};
