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
	int traverse(TreeNode *cur, int &ans) {
		if (cur == nullptr) { return -1; }
		int lc = traverse(cur->left, ans), rc = traverse(cur->right, ans);
		int mx = 0, len = 0;
		if (cur->left != nullptr && cur->left->val == cur->val) {
			mx = max(mx, 1+lc);
			len += lc + 1;
		}
		if (cur->right != nullptr && cur->right->val == cur->val) {
			mx = max(mx, 1+rc);
			len += rc + 1;
		}

		ans = max(ans, len);
		return mx;
	}

	int longestUnivaluePath(TreeNode* root) {
		int ans = 0;
		traverse(root, ans);
		return ans;
	}
};
