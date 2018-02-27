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
	int traverse(TreeNode *cur, int v) {
		int sm = 0;
		v = v * 10 + cur->val;
		if (cur->left == nullptr && cur->right == nullptr) {
			return v;
		}

		if (cur->left != nullptr) { sm += traverse(cur->left, v); }
		if (cur->right != nullptr) { sm += traverse(cur->right, v); }

		return sm;
	}

    int sumNumbers(TreeNode *root) {
		if (root == nullptr) { return 0; }
		return traverse(root, 0);
    }
};
