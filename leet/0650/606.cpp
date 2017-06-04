/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
	void preorder(TreeNode *t, bool is_root, string &out) {
		if (!is_root) { out += '('; }

		if (t != nullptr) {
			static char nbuff[32];
			snprintf(nbuff, sizeof(nbuff), "%d", t->val);
			out  += nbuff;

			if (t->left != nullptr) { 
				preorder(t->left, false, out);
				if (t->right != nullptr) { preorder(t->right, false, out); }
			} else if (t->right != nullptr) {
				preorder(t->left, false, out);
				preorder(t->right, false, out);
			}
		}

		if (!is_root) { out += ')'; }
	}
	string tree2str(TreeNode* t) {
		string out;
		preorder(t, true, out);
		return out;
	}
};
