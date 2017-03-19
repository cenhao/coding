struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) { return 0; }
		int v;
		int d = depth(root, v);
		return v;
	}

	int depth(TreeNode *cur, int &v) {
		if (cur == NULL) {
			v = 0;
			return 0;
		}
		int lv, rv;
		int ld = depth(cur->left, lv);
		int rd = depth(cur->right, rv);
		int mx = max(max(lv, rv), ld+rd);
		v = mx;
		return max(lv, rv) + 1;
	}
};
