/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	TreeNode* build(int cnt, ListNode* &cur) {
		if (cnt <= 0) { return nullptr; }
		int rem = cnt - 1;
		int l = rem / 2;
		int r = rem - l;

		TreeNode *pl = build(l, cur);
		TreeNode *pn = new TreeNode(cur->val);
		cur = cur->next;
		TreeNode *pr = build(r, cur);
		pn->left = pl; pn->right = pr;
		return pn;
	}

    TreeNode* sortedListToBST(ListNode* head) {
		int cnt = 0;
		ListNode *cur = head;
		while (cur != nullptr) {
			++cnt; cur = cur->next;
		}

		return build(cnt, head);
    }
};
