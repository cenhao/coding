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
	void traverse(TreeNode *cur, int &ans, double &mn, double target) {
		if (cur == nullptr) { return; }
		double diff = fabs(target-cur->val);
		if (diff < mn) {
			mn = diff;
			ans = cur->val;
		}

		if (cur->val > target) {
			traverse(cur->left, ans, mn, target);
		} else {
			traverse(cur->right, ans, mn, target);
		}
	}
    int closestValue(TreeNode* root, double target) {
		double mn = 1e15;
		int ans;
		traverse(root, ans, mn, target);
		return ans;
    }
};
