struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		int mn = 0x7fffffff;
		int pre = -1;
		find(root, pre, mn);
		return mn;
	}

	void find(TreeNode* cur, int &pre, int &mn) {
		if (cur == NULL) { return; }
		find(cur->left, pre, mn);
		if (pre != -1) { mn = min(mn, cur->val-pre); }
		pre = cur->val;
		find(cur->right, pre, mn);
	}
};
