#include <bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
	void dfs(TreeNode *cur, const vector<pair<int, int>> &vec, int d, int &idx) {
		if (idx >= vec.size()) { return; }
		if (vec[idx].second == d + 1) {
			cur->left = new TreeNode(vec[idx++].first);
			dfs(cur->left, vec, d+1, idx);

			if (idx<vec.size() && vec[idx].second == d+1) {
				cur->right = new TreeNode(vec[idx++].first);
				dfs(cur->right, vec, d+1, idx);
			}
		}
	}
    TreeNode* recoverFromPreorder(string s) {
		int cnt = 0, v = 0;
		vector<pair<int, int>> vec; 
		for (int i=0; i<=s.length(); ++i) {
			if (i==s.length() || (s[i]=='-' && v!=0)) {
				vec.emplace_back(make_pair(v, cnt));
				v = 0;
				cnt = 1;
			} else if (s[i]>='0' && s[i]<='9') {
				v = v * 10 + s[i] - '0';
			} else {
				++cnt;
			}
		}

		TreeNode root(0);
		int idx = 0;
		dfs(&root, vec, -1, idx);
		return root.left;
    }
};
int main() {
	string s; cin >> s;
	Solution sol;
	sol.recoverFromPreorder(s);
	return 0;
}
