#include <algorithm>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int mx;
	vector<int> findMode(TreeNode* root) {
		vector<int> ret;
		if (root == NULL) { return ret; }
		mx = 0;

		unordered_map<int, int> hashmap;
		inorder(root, hashmap);

		for (auto &e : hashmap) {
			if (e.second == mx) { ret.push_back(e.first); }
		}

		return ret;
	}

	void inorder(TreeNode *cur, unordered_map<int, int> &hashmap) {
		if (cur == NULL) { return; }
		mx = max(mx, ++hashmap[cur->val]);
		inorder(cur->left, hashmap);
		inorder(cur->right, hashmap);
	}
};
