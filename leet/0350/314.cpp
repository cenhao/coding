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
    vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) { return ans; }
		unordered_map<int, vector<int>> hm;
		int mn = 0x7fffffff, mx = 0x80000000;
		pair<TreeNode*, int> tmp = make_pair(root, 0);
		queue<pair<TreeNode*, int>> q;
		q.push(tmp);
		while (!q.empty()) {
			tmp = q.front(); q.pop();
			hm[tmp.second].push_back(tmp.first->val);
			mx = max(mx, tmp.second);
			mn = min(mn, tmp.second);
			if (tmp.first->left != nullptr) {
				q.push(make_pair(tmp.first->left, tmp.second-1));
			}
			if (tmp.first->right != nullptr) {
				q.push(make_pair(tmp.first->right, tmp.second+1));
			}
		}

		for (int i=mn; i<=mx; ++i) { ans.push_back(move(hm[i])); }
		return ans;
    }
};
