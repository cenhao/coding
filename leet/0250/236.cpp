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
	TreeNode* traverse(TreeNode *cur, TreeNode *p, TreeNode *q) {
		if (cur == nullptr) { return nullptr; }
		if (cur == p || cur == q) { return cur; }
		auto *left = traverse(cur->left, p, q);
		auto *right = traverse(cur->right, p, q);
		return left == nullptr ?
			right :
			(right == nullptr ? left : cur);
	}
	int check(TreeNode *cur, TreeNode *p, TreeNode *q) {
		if (cur == nullptr) { return 0; }
		return check(cur->left, p, q) + check(cur->right, p, q) + ((cur==p || cur==q) ? 1:0);
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		auto *lca = traverse(root, p, q);
		return check(lca, p, q) == 2 ? lca : nullptr;
    }
};
