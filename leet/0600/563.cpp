struct TreeNode {
	int val;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int ans = 0;
	int findTilt(TreeNode* root) {
		if (root == NULL) { return 0; }
		int ans = 0;
		traverse(root, ans);
		return ans;
	}

	int traverse(TreeNode *cur, int &ans) {
		if (cur == NULL) { return 0; }
		int lv = traverse(cur->left, ans);
		int rv = traverse(cur->right, ans);
		ans += abs(lv - rv);
		return lv + rv + cur->val;
	}
};
