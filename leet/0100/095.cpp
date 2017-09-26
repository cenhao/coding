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
	void generate(TreeNode *cur, vector<TreeNode*> &tmp, int v) {
		if (cur == nullptr) {
			tmp.push_back(new TreeNode(v));
			return;
		}

		generate(cur->right, tmp, v);
		for (auto &ptr : tmp) {
			TreeNode *nptr = new TreeNode(cur->val);
			nptr->left = cur->left;
			nptr->right = ptr;
			ptr = nptr;
		}
		TreeNode *nptr = new TreeNode(v);
		nptr->left = cur;
		tmp.push_back(nptr);
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans;
		if (n == 0) { return ans; }

		ans.push_back(nullptr);
		for (int i=1; i<=n; ++i) {
			vector<TreeNode*> tmp;
			for (auto ptr : ans) {
				vector<TreeNode*> sub_tmp;
				generate(ptr, sub_tmp, i);
				move(sub_tmp.begin(), sub_tmp.end(), back_inserter(tmp));
			}
			ans = move(tmp);
		}

		return ans;
	}
};
