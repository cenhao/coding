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
	bool isSymmetric(TreeNode *l, TreeNode *r) {
		if (l == nullptr || r == nullptr) { return l == r; }
		if (l->val != r->val) { return false; }
		return isSymmetric(l->right, r->left) && isSymmetric(l->left, r->right);
	}

	bool isSymmetric(TreeNode *root) {
		if (root == nullptr) { return true; }
		return isSymmetric(root->left, root->right);
	}
};
