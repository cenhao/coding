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
	void rob(TreeNode *cur, int opt[]) {
		if (cur == nullptr) {
			opt[0] = opt[1] = 0;
			return;
		}
		int lopt[2], ropt[2];
		rob(cur->left, lopt);
		rob(cur->right, ropt);
		opt[0] = cur->val + lopt[1] + ropt[1];
		opt[1] = max(lopt[0], lopt[1]) + max(ropt[0], ropt[1]);
	}
    int rob(TreeNode* root) {
		int opt[2];
		rob(root, opt);
		return max(opt[0], opt[1]);
    }
};
