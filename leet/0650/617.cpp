class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr && t2 == nullptr) { return nullptr; }
		TreeNode *cur = new TreeNode(0);
		if (t1 != nullptr) { cur->val += t1->val; }
		if (t2 != nullptr) { cur->val += t2->val; }
		TreeNode *t1c = (t1 == nullptr) ? nullptr : t1->left;
		TreeNode *t2c = (t2 == nullptr) ? nullptr : t2->left;
		cur->left = mergeTrees(t1c, t2c);
		t1c = (t1 == nullptr) ? nullptr : t1->right;
		t2c = (t2 == nullptr) ? nullptr : t2->right;
		cur->right = mergeTrees(t1c, t2c);
		return cur;
	}
};
