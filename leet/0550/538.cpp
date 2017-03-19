struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		convert(root, 0);
		return root;
	}

	int convert(TreeNode *cur, int adj) {
		if (cur == NULL) { return 0; }
		int rsum = convert(cur->right, adj);
		int sum = cur->val;
		cur->val += rsum + adj;
		sum += convert(cur->left, cur->val);
		return sum + rsum;
	}
};
