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
	bool findInternal(TreeNode *cur, TreeNode *root, int k) {
		if (cur == nullptr) { return false; }
		if (findInternal(cur->left, root, k)) { return true; }
		int target = k - cur->val;
		if (target < cur->val) { return false; }
		TreeNode *tmp = root;
		while (tmp != nullptr && tmp->val != target) {
			tmp = tmp->val < target ? tmp->left : tmp->right;
		}
		if (tmp != nullptr && tmp != cur) { return true; }
		return findInternal(cur->right, root, k);
	}
    bool findTarget(TreeNode* root, int k) {
		return findInternal(root, root, k);
    }
};
