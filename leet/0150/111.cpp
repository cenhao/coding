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
    int minDepth(TreeNode* root) {
		if (root == nullptr) { return 0; }
		int lv = minDepth(root->left), rv = minDepth(root->right);
		if (lv == 0 || rv == 0) { return max(lv, rv) + 1; }
		return min(lv, rv) + 1;
    }
};
