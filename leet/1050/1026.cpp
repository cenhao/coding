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
	int traverse(TreeNode *cur, int mx, int mn) {
		if (cur == nullptr) { return -1; }
		mx = max(mx, cur->val);
		mn = min(mn, cur->val);
		int ret = abs(mx - mn);
		ret = max(ret, traverse(cur->left, mx, mn));
		ret = max(ret, traverse(cur->right, mx, mn));
		return ret;
	}
    int maxAncestorDiff(TreeNode* root) {
		return traverse(root, -1, 100001);
    }
};
