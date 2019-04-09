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
	const int MOD = 1000000007;
	int traverse(TreeNode* cur, int path) {
		path = (((path << 1) % MOD) + cur->val) % MOD;
		if (cur->left == nullptr && cur->right == nullptr) {
			printf("%d\n", path);
			return path;
		}
		int ans = 0;
		if (cur->left != nullptr) {
			ans += traverse(cur->left, path);
		}
		if (cur->right != nullptr) {
			ans += traverse(cur->right, path);
		}
		return ans % MOD;
	}

    int sumRootToLeaf(TreeNode* root) {
		return traverse(root, 0);
    }
};
