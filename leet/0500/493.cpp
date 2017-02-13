#include <algorithm>
#include <cstdint>
#include <cinttypes>
#include <iostream>
#include <vector>
using namespace std;

struct STN {
	int l, r;
	int cnt;
} nodes[200000+10];
class Solution {
public:
	void build(int cur, int l, int r) {
		nodes[cur].l =l; nodes[cur].r = r;
		nodes[cur].cnt = 0;

		if (l == r) { return; }
		int lc = cur * 2, rc = cur * 2 + 1;
		int le = (l + r) >> 1;
		build(lc, l, le);
		build(rc, le+1, r);
	}

	void add(int cur, int p) {
		++nodes[cur].cnt;
		if (nodes[cur].l == p && nodes[cur].r == p) {
			return;
		}
		int le = (nodes[cur].l + nodes[cur].r) >> 1;
		if (p <= le) {
			add(cur*2, p);
		} else {
			add(cur*2+1, p);
		}
	}

	int query(int cur, int l, int r) {
		if (nodes[cur].l == l && nodes[cur].r == r) {
			return nodes[cur].cnt;
		}
		int le = (nodes[cur].l + nodes[cur].r) >> 1;
		if (r <= le) {
			return query(cur*2, l, r);
		} else if (l > le) {
			return query(cur*2+1, l, r);
		} 

		return query(cur*2, l, le) + query(cur*2+1, le+1, r);
	}

	int find(int64_t v, vector<int64_t> &arr, int s) {
		int l = 0, r = s, m;
		while (l <= r) {
			m = (l+r) >> 1;
			if (arr[m] <= v) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return r;
	}

	int reversePairs(vector<int>& nums) {
		if (nums.size() <= 1) { return 0; }

		vector<int64_t> n2(nums.size());
		for (int i=0; i<nums.size(); ++i) {
			n2[i] = nums[i];
			n2[i] *= 2;
		}

		sort(n2.begin(), n2.end());
		int pos = 0;
		for (int i=1; i<n2.size(); ++i) {
			if (n2[i] != n2[pos]) {
				n2[++pos] = n2[i];
			}
		}

		build(1, 0, pos);
		int ans = 0;

		for (int i=nums.size()-1; i>=0; --i) {
			int p = find(nums[i]-1, n2, pos);
			if (p >= 0) {
				ans += query(1, 0, p);
			}

			int64_t tmp = nums[i];
			tmp *= 2;
			p = find(tmp, n2, pos);
			add(1, p);
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.reversePairs(v) << endl;
	return 0;
}
