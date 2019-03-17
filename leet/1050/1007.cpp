#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int check(int v, vector<int> &a, vector<int>& b) {
		int sz = a.size();
		int cnt = 0;
		for (int i=0; i<sz; ++i) {
			if (a[i] != v) {
				if (b[i] == v) {
					++cnt;
				} else {
					return -1;
				}
			}
		}
		return cnt;
	}

	int minDominoRotations(vector<int>& a, vector<int>& b) {
		int mn = -1;
		for (int i=1; i<=6; ++i) {
			int tmp = check(i, a, b);
			if (tmp >= 0 && (mn == -1 || mn > tmp)) { mn = tmp; }
			tmp = check(i, b, a);
			if (tmp >= 0 && (mn == -1 || mn > tmp)) { mn = tmp; }
		}
		return mn;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	for (int i=0; i<n; ++i) { cin >> b[i]; }
	Solution sol;
	cout << sol.minDominoRotations(a, b) << endl;
	return 0;
}
