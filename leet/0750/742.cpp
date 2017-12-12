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
	int find(TreeNode *cur, int k, int d, unordered_set<int> &ds) {
		if (cur == NULL) { return -1; }
		if (cur->val == k) {
			ds.insert(k);
			return d;
		}

		int v = find(cur->left, k, d+1, ds);
		if (v < 0) {
			v = find(cur->right, k, d+1, ds);
		}
		if (v >= 0) { ds.insert(cur->val); }
		return v;
	}

	void calc(TreeNode *cur, int k, int d, int pd, bool hit, int &md, int &ans, unordered_set<int> &ds) {
		if (cur == NULL) { return; }
		if (cur->val == k) {
			hit = true;
			d = 0;
		}
		if (cur->left == NULL && cur->right == NULL) {
			int tmp = d + (hit ? 0 : pd);
			if (md == -1 || tmp < md) {
				md = tmp;
				ans = cur->val;
			}
			return;
		}

		if (ds.find(cur->val) != ds.end()) {
			--pd;
			d = 0;
		}
		calc(cur->left, k, d+1, pd, hit, md, ans, ds);
		calc(cur->right, k, d+1, pd, hit, md, ans, ds);
	}
    int findClosestLeaf(TreeNode* root, int k) {
		unordered_set<int> ds;
		int d = find(root, k, 0, dm);
		int md = -1, ans;
		calc(root, k, 0, d+1, false, md, ans, ds);
		return ans;
    }
};
