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
	void dfs(TreeNode *cur, vector<int> &lw, vector<int> &rw, int d, int v) {
		if (cur == nullptr) { return; }
		if (d >= lw.size()) { lw.push_back(v); }
		if (d >= rw.size()) { rw.push_back(v); }
		lw[d] = min(v, lw[d]);
		rw[d] = max(v, rw[d]);
		dfs(cur->left, lw, rw, d+1, v*2-1);
		dfs(cur->right, lw, rw, d+1, v*2);
	}

    int widthOfBinaryTree(TreeNode* root) {
		vector<int> lw, rw;
		dfs(root, lw, rw, 0, 1);
		int mx = 0;
		for (int i=0; i<lw.size(); ++i) { mx = max(mx, rw[i] - lw[i]); }
		return mx+1;
    }
};
