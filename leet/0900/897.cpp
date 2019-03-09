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
    TreeNode* increasingBST(TreeNode* root) {
		TreeNode head(-1);
		TreeNode *nxt = &head;
		traverse(root, nxt);
		return head.right;
    }

	void traverse(TreeNode *cur, TreeNode *&nxt) {
		if (cur == nullptr) { return; }
		traverse(cur->left, nxt);
		nxt->right = new TreeNode(cur->val);
		nxt = nxt->right;
		traverse(cur->right, nxt);
	}
};
