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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int sz = inorder.size();
		unordered_map<int, int> w;
		TreeNode root(0);
		for (int i=0; i<sz; ++i) { w[inorder[i]] = i; }
		for (int i=sz-1; i>=0; --i) {
			bool right = true;
			TreeNode *cur = root.right, *pre = &root;
			while (cur != nullptr) {
				pre = cur;
				if (w[postorder[i]] < w[cur->val]) {
					right = false;
					cur = cur->left;
				} else {
					right = true;
					cur = cur->right;
				}
			}

			if (right) {
				pre->right = new TreeNode(postorder[i]);
			} else {
				pre->left = new TreeNode(postorder[i]);
			}
		}

		return root.right;
    }
};
