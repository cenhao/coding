struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void traverse(TreeNode *cur, bool is_left, bool is_right, vector<int> &ans) {
		if (is_left) { ans.push_back(cur->val); }

		bool hl = (cur->left != NULL), hr = (cur->right != NULL);
		if (hl) {
			traverse(cur->left, is_left, !hr && !is_left && is_right, ans);
		}
		
		if (hr) {
			traverse(cur->right, !hl && !is_right && is_left, is_right, ans);
		}

		if (!hl && !hr && !is_left && !is_right) {
			ans.push_back(cur->val);
		}

		if (is_right && !is_left) {
			ans.push_back(cur->val);
		}
	}

	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int> ans;
		if (root == NULL) { return ans; }
		traverse(root, true, true, ans);
		return ans;
	}
};
