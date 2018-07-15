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
	int get_cnt(TreeNode *cur, int td, int d) {
		if (cur == nullptr) { return 0; }
		if (d == td) { return 1; }
		return get_cnt(cur->left, td, d+1) + get_cnt(cur->right, td, d+1);
	}
	int get(TreeNode *cur, int td, int d, int cnt, TreeNode **ans) {
		if (cur == nullptr) { return 0; }
		if (td == d) {
			if (cnt == 1) { *ans = cur; }
			return 1;
		}
		int sm = get(cur->left, td, d+1, cnt, ans) + get(cur->right, td, d+1, cnt, ans);
		if (cnt == sm && *ans == nullptr) { *ans = cur; }
		return sm;
	}

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if (root == nullptr) { return nullptr; }
		int d = get_depth(root);
		int cnt = get_cnt(root, d, 1);
		TreeNode *ans = nullptr;
		get(root, d, 1, cnt, &ans);
		return ans;
    }
};
