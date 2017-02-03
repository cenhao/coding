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
