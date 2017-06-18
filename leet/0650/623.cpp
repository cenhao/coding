class Solution {
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (root == nullptr) { return root; }
		if (d == 1) {
			TreeNode *ret = new TreeNode(v);
			ret->left = root;
			return ret;
		}

		if (d == 2) {
			TreeNode *left = new TreeNode(v);
			left->left = root->left;
			root->left = left;
			TreeNode *right = new TreeNode(v);
			right->right = root->right;
			root->right = right;
			return root;
		}

		addOneRow(root->left, v, d-1);
		addOneRow(root->right, v, d-1);
		return root;
	}
};
