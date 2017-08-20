/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int sumTree(TreeNode *cur) {
		if (cur == nullptr) { return 0; }
		return cur->val + sumTree(cur->left) + sumTree(cur->right);
	}

	int scan(TreeNode *cur, int &ssm, int sm, bool is_root) {
		if (cur == nullptr) { return false; }
		int lsm = 0, rsm = 0;
		if (scan(cur->left, lsm, sm, false)) { return true; }
		if (scan(cur->right, rsm, sm, false)) { return true; }
		ssm = lsm + rsm + cur->val;
		return (ssm == sm - ssm) && !is_root;
	}

    bool checkEqualTree(TreeNode* root) {
		int sm = sumTree(root);
		int tmp;
		return scan(root, tmp, sm);
    }
};
