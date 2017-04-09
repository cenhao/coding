#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void traverse(TreeNode* cur, int &mx, int &ivs_ret, int &ive_ret, int &dvs_ret, int &dve_ret) {
		if (cur == NULL) { return; }

		int rivs, rive, rdvs, rdve;
		int livs, live, ldvs, ldve;
		int ivs = 1, ive = 1, dvs = 1, dve = 1;
		int iv = 1, dv = 1;
		ivs_ret = ive_ret = dvs_ret = dve_ret = 1;
		traverse(cur->left, mx, livs, live, ldvs, ldve);
		traverse(cur->right, mx, rivs, rive, rdvs, rdve);

		if (cur->right != NULL) {
			if (cur->right->val + 1 == cur->val) {
				dv += max(rdvs, rive);
				dvs_ret += max(rdvs, rive);
			} else if (cur->val + 1== cur->right->val) {
				iv += max(rivs, rdve);
				ivs_ret += max(rivs, rdve);
			}
		}

		if (cur->left != NULL) {
			if (cur->left->val + 1 == cur->val) {
				iv += max(live, ldvs);
				ive_ret += max(live, ldvs);
			} else if (cur->val + 1 == cur->left->val) {
				dv += max(ldve, livs);
				dve_ret += max(ldve, livs);
			}
		}

		mx = max(mx, max(iv, dv));
	}

	int longestConsecutive(TreeNode* root) {
		int mx = 0;
		int ivs, ive, dvs, dve;
		traverse(root, mx, ivs, ive, dvs, dve);
		return mx;
	}
};

int main() {
	TreeNode r(4);
	TreeNode n3_2(3);
	TreeNode n6_2(6);
	r.left = &n3_2; r.right = &n6_2;

	TreeNode n2_3(2);
	TreeNode n4_3(4);
	n3_2.left = &n2_3; n3_2.right = &n4_3;

	TreeNode n1_4(1);
	TreeNode n3_4(3);
	n2_3.left = &n1_4; n2_3.right = &n3_4;

	TreeNode n5_4(5);
	n4_3.left = &n5_4;

	Solution sol;
	cout << sol.longestConsecutive(&r) << endl;
}
