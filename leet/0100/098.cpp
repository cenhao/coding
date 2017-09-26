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
	bool isValidBST(TreeNode *cur, int64_t mn, int64_t mx) {
		if (cur == nullptr) { return true; }
		if (cur->val >= mx || cur->val <= mn) { return false; }
		return isValidBST(cur->left, mn, cur->val) && isValidBST(cur->right, cur->val, mx);
	}
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, -0x7ffffffff, 0x7ffffffff);
	}
};
