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
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<pair<TreeNode*, int>> stk;
		stk.push(make_pair(root, 0));

		while (!stk.empty()) {
			auto p = stk.top(); stk.pop();
			if (p.first == nullptr) { continue; }
			if (p.second == 0) {
				stk.push(make_pair(p.first, 1));
				stk.push(make_pair(p.first->left, 0));
			} else if (p.second == 1) {
				stk.push(make_pair(p.first, 2));
				stk.push(make_pair(p.first->right, 0));
			} else {
				ans.push_back(p.first->val);
			}
		}

		return ans;
    }
};
