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
	void traverse(TreeNode *cur, double tar, queue<int> &q, int k) {
		const static double EPS = 1e-7;
		if (cur == nullptr) { return; }
		traverse(cur->left, tar, q, k);
		if (q.size() < k) {
			q.push(cur->val);
		} else if (fabs(cur->val-tar) <= fabs(q.front()-tar)-EPS) {
			q.pop();
			q.push(cur->val);
		}
		traverse(cur->right, tar, q, k);
	}
    vector<int> closestKValues(TreeNode* root, double target, int k) {
		queue<int> q;
		vector<int> ans(k);
		traverse(root, target, q, k);
		for (int i=0; i<k; ++i) {
			ans[i] = q.front();
			q.pop();
		}
		return ans;
    }
};
