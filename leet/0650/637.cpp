class Solution {
public:
	void dfs(TreeNode *root, int d, vector<int64_t> &sum, vector<int> &cnt) {
		if (root == nullptr) { return ; }
		if (d >= sum.size()) {
			sum.push_back(0);
			cnt.push_back(0);
		}
		sum[d] += root->val;
		++cnt[d];
		dfs(root->left, d+1, sum, cnt);
		dfs(root->right, d+1, sum, cnt);
	}
    vector<double> averageOfLevels(TreeNode* root) {
		vector<int64_t> sum;
		vector<int> cnt;
		dfs(root, 0, sum, cnt);
		vector<double> ans(sum.size());
		for (int i=0, sz=sum.size(); i<sz; ++i) {
			ans[i] = sum[i] / double(cnt[i]);
		}

		return ans;
    }
};
