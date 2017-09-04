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
	void find(TreeNode *cur, int &mn, int &smn) {
		if (cur == nullptr) { return ; }
		if (cur->val < mn) {
			smn = mn;
			mn = cur->val;
		} else if (cur->val != mn && (smn == -1 || cur->val < smn)) {
			smn = cur->val;
		}
		find(cur->left, mn, smn);
		find(cur->right, mn, smn);
	}
    int findSecondMinimumValue(TreeNode* root) {
		if (root == nullptr) { return -1; }
		int mn = root->val, smn = -1;
		find(root, mn, smn);
		return smn;
    }
};
