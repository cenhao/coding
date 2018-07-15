#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void get_cnt(int v, vector<int> &arr) {
		string s = to_string(v);
		for (auto c: s) { ++arr[c-'0']; }
	}
	bool reorderedPowerOf2(int n) {
		vector<vector<int>> cnt(32, vector<int>(10, 0));
		for (int i=0; i<32; ++i) { get_cnt(1<<i, cnt[i]); }
		vector<int> na(10, 0);
		get_cnt(n, na);
		bool ok = false;
		for (int i=0; i<32; ++i) {
			int tmp = true;
			for (int j=0; j<10 && tmp; ++j) {
				if (na[j] != cnt[i][j]) { tmp = false; }
			}
			if (tmp) {
				ok = true; break;
			}
		}

		return ok;
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.reorderedPowerOf2(n) << endl;
	return 0;
}
