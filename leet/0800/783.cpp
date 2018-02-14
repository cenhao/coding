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
	int proc(TreeNode *cur, int *pre, int &mn) {
		if (cur->left != nullptr) {
			int pv = proc(cur->left, pre, mn);
			mn = min(mn, cur->val - pv);
		} else if (pre != nullptr) {
			mn = min(mn, cur->val - *pre);
		}
		int npv = cur->val;
		if (cur->right != nullptr) {
			npv = proc(cur->right, &npv, mn);
		}

		return npv;
	}
	int minDiffInBST(TreeNode* root) {
		int mn = 0x7fffffff;
		proc(root, nullptr, mn);
		return mn;
	}
};
