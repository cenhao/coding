#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int candy(vector<int> &r) {
		int len = r.size();
		int sum = 1;
		for (int i=1, pp=0, pc=1, tv=1; i<len; ++i) {
			if (r[i] > r[i-1]) {
				tv = ++pc;
				pp = i;
			} else if (r[i] == r[i-1]) {
				tv = pc = 1;
				pp = i;
			} else {
				pc = 1;
				sum += i-pp-1;
				if (i-pp >= tv) { ++tv; ++sum; }
			}

			sum += pc;
		}

		return sum;
	}
};

int main() {
	int n; cin >> n;
	vector<int> c(n); for (int i=0; i<n; ++i) cin >> c[i];
	Solution sol;
	cout << sol.candy(c) << endl;
	return 0;
}
