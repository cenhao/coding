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
	int traverse(TreeNode *cur, TreeNode *tar, int k, int dist, vector<int> &ans) {
		if (cur == nullptr) { return -1; }
		if (dist < 0) {
			if (cur == tar) {
				if (k == 0) {
					ans.push_back(cur->val);
				} else {
					traverse(cur->left, tar, k, 1, ans);
					traverse(cur->right, tar, k, 1, ans);
				}
				return 0;
			} else {
				int ld = traverse(cur->left, tar, k, dist, ans);
				if (ld >= 0) {
					dist = ld + 1;
					if (dist == k) {
						ans.push_back(cur->val);
					} else if (dist < k) {
						traverse(cur->right, tar, k, dist+1, ans);
					}
					return dist;
				}
				int rd = traverse(cur->right, tar, k, dist, ans);
				if (rd >= 0) {
					dist = rd + 1;
					if (dist == k) {
						ans.push_back(cur->val);
					} else if (dist < k) {
						traverse(cur->left, tar, k, dist+1, ans);
					}
					return dist;
				}
			}
		} else {
			if (dist == k) {
				ans.push_back(cur->val);
			} else if (dist < k) {
				traverse(cur->left, tar, k, dist+1, ans);
				traverse(cur->right, tar, k, dist+1, ans);
			}
		}
		return -1;
	}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		vector<int> ans;
		traverse(root, target, K, -1, ans);
		return ans;
    }
};
