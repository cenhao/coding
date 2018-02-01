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
    void flatten(TreeNode* root) {
		TreeNode *cur = root;
		while (cur != nullptr) {
			if (cur->left != nullptr) {
				TreeNode *lr = cur->left;
				while (lr->right != nullptr) { lr = lr->right; }
				lr->right = cur->right;
				cur->right = cur->left;
				cur->left = nullptr;
			}
			cur = cur->right;
		}
    }
};
