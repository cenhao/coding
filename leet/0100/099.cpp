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
	TreeNode *traverse(TreeNode *cur, TreeNode *pre, TreeNode **mxp, TreeNode **mnp) {
		if (cur == nullptr) { return nullptr; }
		TreeNode *tmp = traverse(cur->left, pre, mxp, mnp);
		if (tmp != nullptr) { pre = tmp; }
		if (pre != nullptr) {
			if (cur->val < pre->val) {
				if (*mxp == nullptr) { *mxp = pre; }
				*mnp = cur;
			}
		}
		tmp = traverse(cur->right, cur, mxp, mnp);
		return (tmp == nullptr) ? cur : tmp;
	}

	// assuming there's no duplicates
	void recoverTree(TreeNode* root) {
		TreeNode *mxp = nullptr, *mnp = nullptr;
		traverse(root, nullptr, &mxp, &mnp);
		if (*mxp != nullptr && *mnp != nullptr) {
			swap(mxp->val, mnp->val);
		}
	}
};
