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
	int traverse(TreeNode *cur, int &mxc) {
		mxc = 0;
		if (cur == nullptr) { return 0; }
		int mx = cur->val, lv = 0, rv = 0;
		if (cur->left != nullptr) { mx = max(mx, traverse(cur->left, lv)); }
		if (cur->right != nullptr) { mx = max(mx, traverse(cur->right, rv)); }
		mxc = max(0, max(lv, rv) + cur->val);
		mx = max(cur->val+lv+rv, mx);
		return mx;
	}
	int maxPathSum(TreeNode* root) {
		int mxc;
		return traverse(root, mxc);
    }
};
