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
	void build(TreeNode *cur, const vector<int> &nums, int &idx) {
		while (idx < nums.size()) {
			if (nums[idx] > cur->val) { return; }
			TreeNode *tmp = new TreeNode(nums[idx++]);
			tmp->left = cur->right;
			cur->right = tmp;
			build(tmp, nums, idx);
		}
	}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode vroot(0x7fffffff);
		int idx = 0;
		build(&vroot, nums, idx);
		return vroot.right;
    }
};
