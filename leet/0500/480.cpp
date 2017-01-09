#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct AVLNode {
	AVLNode(int v) {
		lc = rc = NULL;
		repeat = depth = count = 1;
		val = v;
	}
	AVLNode *lc, *rc;
	int repeat;
	int count;
	int depth;
	int val;
};

AVLNode *root;

AVLNode* adjust(AVLNode *cur);

AVLNode* right_rotate(AVLNode *cur) {
	AVLNode *tmp = cur->lc;
	int ld, rd, lc, rc;
	ld = tmp->lc == NULL ? 0 : tmp->lc->depth;
	rd = tmp->rc == NULL ? 0 : tmp->rc->depth;

	if (ld > rd) {
		cur->lc = tmp->rc;
		cur = adjust(cur);
		tmp->rc = cur;
		tmp = adjust(tmp);
		cur = tmp;
	} else {
		AVLNode *trc = tmp->rc;
		tmp->rc = trc->lc;
		tmp = adjust(tmp);
		cur->lc = trc->rc;
		cur = adjust(cur);
		trc->lc = tmp;
		trc->rc = cur;
		cur = trc;
	}

	return adjust(cur);
}

AVLNode* left_rotate(AVLNode *cur) {
	AVLNode *tmp = cur->rc;
	int ld, rd, lc, rc;
	ld = tmp->lc == NULL ? 0 : tmp->lc->depth;
	rd = tmp->rc == NULL ? 0 : tmp->rc->depth;

	if (rd > ld) {
		cur->rc = tmp->lc;
		cur = adjust(cur);
		tmp->lc = cur;
		cur = tmp;
	} else {
		AVLNode *tlc = tmp->lc;
		tmp->lc = tlc->rc;
		tmp = adjust(tmp);
		cur->rc = tlc->lc;
		cur = adjust(cur);
		tlc->lc = cur;
		tlc->rc = tmp;
		cur = tlc;
	}

	return adjust(cur);
}

AVLNode* adjust(AVLNode *cur) {
	int ld = cur->lc == NULL ? 0 : cur->lc->depth;
	int rd = cur->rc == NULL ? 0 : cur->rc->depth;

	if (ld > rd + 1) {
		cur = right_rotate(cur);
	} else if (ld + 1 < rd) {
		cur = left_rotate(cur);
	} else {
		cur->depth = max(ld, rd) + 1;
		int lc = cur->lc == NULL ? 0 : cur->lc->count;
		int rc = cur->rc == NULL ? 0 : cur->rc->count;
		cur->count = lc + rc + cur->repeat;
	}

	return cur;
}

AVLNode* insert(AVLNode *cur, int val) {
	if (cur == NULL) {
		return new AVLNode(val);
	}

	if (val < cur->val) {
		cur->lc = insert(cur->lc, val);
	} else if (val > cur->val) {
		cur->rc = insert(cur->rc, val);
	} else {
		++cur->repeat;
	}

	++(cur->count);
	return adjust(cur);
}

AVLNode* pick_max(AVLNode *cur, int *pval, int *prepeat) {
	if (cur->rc == NULL) {
		AVLNode *ret = cur->lc;
		*pval = cur->val; *prepeat = cur->repeat;
		delete cur;
		return ret;
	}

	cur->rc = pick_max(cur->rc, pval, prepeat);
	return adjust(cur);
}

AVLNode* pick_min(AVLNode *cur, int *pval, int *prepeat) {
	if (cur->lc == NULL) {
		AVLNode *ret = cur->rc;
		*pval = cur->val; *prepeat = cur->repeat;
		delete cur;
		return ret;
	}

	cur->rc = pick_min(cur->lc, pval, prepeat);
	return adjust(cur);
}

AVLNode* remove(AVLNode *cur, int val) {
	if (cur == NULL) { return NULL; }
	if (val < cur->val) {
		cur->lc = remove(cur->lc, val);
	} else if (val > cur->val) {
		cur->rc = remove(cur->rc, val);
	} else {
		if (--cur->repeat == 0) {
			if (cur->lc != NULL) {
				cur->lc = pick_max(cur->lc, &cur->val, &cur->repeat);
			} else if (cur->rc != NULL) {
				cur->rc = pick_min(cur->rc, &cur->val, &cur->repeat);
			} else {
				delete cur;
				cur = NULL;
			}
		}
	}

	if (cur != NULL) {
		--(cur->count);
		cur = adjust(cur);
	}

	return cur;
}

int find_kth(AVLNode *cur, int k) {
	int lc, rc;
	lc = cur->lc == NULL ? 0 : cur->lc->count;
	rc = cur->rc == NULL ? 0 : cur->rc->count;

	if (k <= lc) {
		return find_kth(cur->lc, k);
	} else if (k <= lc + cur->repeat) {
		return cur->val;
	} else {
		return find_kth(cur->rc, k-lc-cur->repeat);
	}
}

void clean(AVLNode *cur) {
	if (cur == NULL) { return; }
	clean(cur->lc);
	clean(cur->rc);
	delete cur;
}

class Solution {
	public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		AVLNode *root = NULL;
		int cnt = 0, first = (k+1)/2, second = k / 2 + 1;
		vector<double> ans;
		for (int i=0, end=nums.size(); i<end; ++i) {
			if (i >= k) { root = remove(root, nums[i-k]); }
			root = insert(root, nums[i]);
			if (i >= k-1) {
				double m = 0.0;
				m += find_kth(root, first);
				m += find_kth(root, second);
				m /= 2;
				ans.push_back(m);
			}
		}

		clean(root);
		return ans;
	}
};

int main() {
	int n, k;
	while (cin >> n >> k) {
		vector<int> nums(n);
		for (int i=0; i<n; ++i) { cin >> nums[i]; }
		Solution sol;
		vector<double> ans = move(sol.medianSlidingWindow(nums, k));
		for (int i=0, end=ans.size(); i<end; ++i) {
			cout << ans[i] << endl;
		}
		
		cout << endl;
	}

	return 0;
}
