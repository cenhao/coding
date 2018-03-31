#include <cstdlib>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		visit(root, v);
		return v;
	}

	void visit(TreeNode *cur, vector<int> &v) {
		if (cur == NULL) { return; }
		v.push_back(cur->val);
		visit(cur->left, v);
		visit(cur->right, v);
	}
};

// stack
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == nullptr) { return ans; }
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode *cur = stk.top(); stk.pop();
			while (cur != nullptr) {
				ans.push_back(cur->val);
				if (cur->right != nullptr) { stk.push(cur->right); }
				cur = cur->left;
			}
		}
		return ans;
	}
};

// morris WANRING: crash at run time
class Solution {
public:
	TreeNode *find(TreeNode *cur) {
		while (cur->left != nullptr) { cur = cur->left; }
		return cur;
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		TreeNode *cur = root;
		while (cur != nullptr) {
			ans.push_back(cur->val);
			if (cur->right != nullptr) {
				auto *tmp = find(cur);
				tmp->left = cur->right;
			}

			cur = cur->left;
		}

		return ans;
	}
};
