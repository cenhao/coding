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
	int traverse(TreeNode* cur, int psum) {
		if (cur == nullptr) { return 0; }
		int tv = cur->val;
		int rv = traverse(cur->right, psum);
		cur->val += rv + psum;
		int lv = traverse(cur->left, psum+tv+rv);
		return tv + rv + lv;
	}

    TreeNode* bstToGst(TreeNode* root) {
		traverse(root, 0);
		return root;
    }
};
