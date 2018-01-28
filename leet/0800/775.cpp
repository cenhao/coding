#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int ginv(vector<int> &a, int len) {
		int cnt = 0;
		vector<int> b(len);
		for (int i=1; (1<<(i-1))<=len; ++i) {
			int step = 1 << i;
			int hs = step >> 1;
			for (int j=0; j<len; j+=step) {
				int ls = j, le = min(j + hs, len);
				int rs = le, re = min(le+hs, len);
				int cur = ls;
				while (ls < le && rs < re) {
					if (a[ls] <= a[rs]) {
						b[cur++] = a[ls++];
					} else {
						b[cur++] = a[rs++];
						cnt += le-ls;
					}
				}
				while (ls < le) { b[cur++] = a[ls++]; }
				while (rs < re) { b[cur++] = a[rs++]; }
				for (int k=j; k<re; ++k) { a[k] = b[k]; }
			}
		}

		return cnt;
	}
	bool isIdealPermutation(vector<int>& a) {
		int len = a.size();
		int lcnt = 0;
		for (int i=1; i<len; ++i) {
			if (a[i-1] > a[i]) { ++lcnt; }
		}
		int gcnt = ginv(a, len);
		return lcnt == gcnt;
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n); for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.isIdealPermutation(v) << endl;
	return 0;
}
