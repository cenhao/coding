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
    bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) { return false; }
		if (root->left == nullptr && root->right == nullptr) {
			return root->val == sum;
		}

		int tar = sum - root->val;
		return (root->left != nullptr && hasPathSum(root->left, tar)) ||
			(root->right != nullptr && hasPathSum(root->right, tar));
    }
};
