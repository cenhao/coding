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
	TreeNode* build(const vector<int> &nums, int l, int r) {
		if (l > r) { return nullptr; }
		int m = (l + r) >> 1;
		TreeNode *cur = new TreeNode(nums[m]);
		cur->left = build(nums, l, m-1);
		cur->right = build(nums, m+1, r);
		reutrn cur;
	}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		int sz = nums.size();
		return build(nums, 0, sz-1);
    }
};
