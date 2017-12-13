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
	bool check(TreeNode *cur, int &d) {
		if (cur == nullptr) {
			d = 0;
			return true;
		}

		int ld, rd;
		if (!check(cur->left, ld)) { return false; }
		if (!check(cur->right, rd)) { return false; }
		if (abs(ld-rd) > 1) { return false; }
		d = max(ld, rd) + 1;
		return true;
	}

    bool isBalanced(TreeNode* root) {
		int d;
		return check(root, d);
    }
};
