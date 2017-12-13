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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int sz = preorder.size();
		TreeNode root(0);
		unordered_map<int, int> w(sz);
		for (int i=0; i<sz; ++i) { w[inorder[i]] = i; }
		for (int i=0; i<sz; ++i) {
			TreeNode *pre = &root, *cur = root.left;
			bool left = true;
			while (cur != nullptr) {
				pre = cur;
				if (w[preorder[i]] < w[cur->val]) {
					cur = cur->left;
					left = true;
				} else {
					cur = cur->right;
					left = false;
				}
			}
			if (left) {
				pre->left = new TreeNode(preorder[i]);
			} else {
				pre->right = new TreeNode(preorder[i]);
			}
		}

		return root.left;
    }
};
