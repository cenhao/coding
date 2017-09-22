class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> st;
		TreeNode *cur = root;
		while (cur != nullptr) {
			st.push(cur);
			cur = cur->left;
		}

		while (!st.empty()) {
			cur = st.top(); st.pop();
			ans.push_back(cur->val);
			cur = cur->right;
			while (cur != nullptr) {
				st.push(cur);
				cur = cur->left;
			}
		}

		return ans;
	}
};
