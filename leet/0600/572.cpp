class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		return same(s, t) ||
			(s != nullptr && (isSubtree(s->left, t) || isSubtree(s->right, t)));
	}

	bool same(TreeNode* s, TreeNode* t) {
		if (s == nullptr && t == nullptr) { return true; }
		if (s == nullptr || t == nullptr) { return false; }
		if (s->val != t->val) { return false; }
		return (same(s->left, t->left) && same(s->right, t->right));
	}
};
