struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> findValueMostElement(TreeNode* root) {
		unordered_map<int, int> leftmost;
		int d = find(root, leftmost, 0);
		vector<int> ans(d+1);
		for (int i=0; i<=d; ++i) {
			ans[i] = leftmost[i];
		}

		return ans;
	}

	int find(TreeNode *cur, unordered_map<int, int> &leftmost, int d) {
		if (cur == NULL) { return d - 1; }

		auto it = leftmost.find(d);
		if (it == leftmost.end() || cur->val > it->second) {
			leftmost[d] = cur->val;
		}
		return max(find(cur->left, leftmost, d+1),
				   find(cur->right, leftmost, d+1));
	}
};
