#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int sz = arr.size();
		int cnt = 0;
		for (int i=0, st=0, mx = -1, mn=0x7fffffff; i<sz; ++i) {
			mn = min(mn, arr[i]);
			mx = max(mx, arr[i]);
			if (mn == st && mx == i) {
				++cnt;
				mn = 0x7fffffff; mx = i;
				st = i+1;
			}
		}

		return cnt;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.maxChunksToSorted(a) << endl;
	return 0;
}
