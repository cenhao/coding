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
	TreeNode* traverse(TreeNode *cur, int &k) {
		if (cur == nullptr) { return nullptr; }
		auto *tmp = traverse(cur->left, k);
		if (k == 0) { return tmp; }
		if (--k == 0) { return cur; }
		return traverse(cur->right, k);
	}
    int kthSmallest(TreeNode* root, int k) {
		auto *ans = traverse(root, k);
		return ans->val;
    }
};
