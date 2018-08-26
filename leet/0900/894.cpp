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
	void dfs(int n, vector<TreeNode*> &ans) {
		if (n == 0) {
			ans.push_back(nullptr);
		} else if (n  == 1) {
			ans.push_back(new TreeNode(0));
		} else {
			for (int i=1; i<n-1; ++i) {
				vector<TreeNode*> l, r;
				dfs(i, l);
				dfs(n-1-i, r);
				for (auto pl: l) {
					for (auto pr: r) {
						auto *tmp = new TreeNode(0);
						tmp->l = pl; tmp->r = pr;
						ans.push_back(tmp);
					}
				}
			}
		}
	}
    vector<TreeNode*> allPossibleFBT(int N) {
		vector<TreeNode*> ans;
		dfs(N, ans);
		return ans;
    }
};
