struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int findLeftMostNode(TreeNode* root) {
		int mx = -1, mxd = -1;
		find(root, 0, &mxd, &mx);
		return mx;
	}

	void find(TreeNode *cur, int d, int *pmxd, int *pmx) {
		if (cur == NULL) { return; }

		if (d > *pmxd) {
			*pmxd = d;
			*pmx = cur->val;
		}

		find(cur->left, d+1, pmxd, pmx);
		find(cur->right, d+1, pmxd, pmx);
	}
};
