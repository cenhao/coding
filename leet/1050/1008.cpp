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
	void build(TreeNode *cur, vector<int> &po, int &idx, int mn, int mx) {
		cur->val = po[idx];
		++idx;
		if (idx >= po.size()) { return; }
		if (po[idx] < cur->val) {
			cur->left = new TreeNode(0);
			build(cur->left, po, idx, mn, cur->val);
		}
		if (idx >= po.size()) { return; }
		if (po[idx] < mx) {
			cur->right = new TreeNode(0);
			build(cur->right, po, idx, cur->val, mx);
		}
	}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		TreeNode tmp(0);
		tmp.left = new TreeNode(0);
		int mn = -0x7fffffff, mx = 0x7fffffff, idx = 0;
		build(tmp.left, preorder, idx, mn, mx);
		return tmp.left;
    }
};
