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
	void dfs(TreeNode *cur, int tar, int depth, vector<int> &buff, vector<vector<int>> &ans) {
		if (depth >= buff.size()) { buff.push_back(0); }
		buff[depth-1] = cur->val;
		if (cur->left == nullptr && cur->right == nullptr) {
			if (tar == cur->val) {
				vector<int> tmp(buff.begin(), buff.begin()+depth);
				ans.push_back(move(tmp));
			}
			return;
		}

		tar -= cur->val;
		if (cur->left != nullptr) {
			dfs(cur->left, tar, depth+1, buff, ans);
		}
		if (cur->right != nullptr) {
			dfs(cur->right, tar, depth+1, buff, ans);
		}
	}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		if (root != nullptr) {
			vector<int> buff;
			dfs(root, sum, 1, buff, ans);
		}
		return ans;
    }
};
