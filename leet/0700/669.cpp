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
	TreeNode* build(TreeNode *cur, int l, int r) {
		if (cur == nullptr) { return cur; }
		if (cur->val < l) { return build(cur->right, l, r); }
		if (cur->val > r) { return build(cur->left, l, r); }
		cur->left = build(cur->left, l, r);
		cur->right = build(cur->right, l, r);
		return cur;
	}
    TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (root == nullptr) { return nullptr; }
		return build(root, L, R);
    }
};
