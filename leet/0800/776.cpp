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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
		vector<TreeNode*> val{ nullptr, nullptr };
		if (root == nullptr) {
			return val;
		}
		if (root->val <= V) {
			val = move(splitBST(root->right, V));
			if (root->right == val[1]) {
				root->right = val[0];
			}
			val[0] = root;
		} else {
			val = move(splitBST(root->left, V));
			if (root->left == val[0]) {
				root->left = val[1];
			}
			val[1] = root;
		}

		return val;
    }
};
