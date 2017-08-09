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
	int get_depth(TreeNode *cur) {
		if (cur == nullptr) { return 0; }
		return max(get_depth(cur->left), get_depth(cur->right)) + 1;
	}
	void fill(TreeNode *cur, int d, int off, int w, vector<vector<string>> &ans) {
		if (cur == nullptr) { return; }
		fill(cur->left, d+1, off, w/2, ans);
		ans[d][off+w] = to_string(cur->val);
		fill(cur->right, d+1, off+w+1, w/2, ans);
	}
    vector<vector<string>> printTree(TreeNode* root) {
		int d = get_depth(root);
		vector<vector<string>> ans(d, vector<string>((1<<d)-1, ""));
		fill(root, 0, 0, ((1<<d)-1)/2, ans);
		return ans;
    }
};
