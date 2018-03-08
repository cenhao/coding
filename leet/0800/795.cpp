#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& a, int L, int R) {
		int len = a.size();
		vector<int> q(len);
		int h = 0, r = 0;
		int last = 0, ans = 0;
		int mx = -1;
		for (int i=0; i<=len; ++i) {
			if (i==len || a[i] > R) {
				for (int j=last; j<i && h<r; ++j) {
					if (j == q[h]) {
						++h;
						ans += i-j;
					} else if (h < r) {
						ans += i-q[h];
					}
				}
				last = i+1;
			} else {
				if (a[i] >= L) {
					q[r++] = i;
				}
			}
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n); for (int i=0; i<n; ++i) { cin >> a[i]; }
	int l, r; cin >> l >> r;
	Solution sol;
	cout << sol.numSubarrayBoundedMax(a, l, r) << endl;
	return 0;
}
