#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int check(vector<int> &s) {
		unordered_set<int> phs, chs;
		phs.insert(0);
		for (int i=0; i<s.size(); ++i) {
			for (auto v: phs) {
				chs.insert(abs(s[i]-v));
				chs.insert(s[i]+v);
			}

			phs = move(chs);
		}
		int mn = 0x7ffffff;
		for (auto v: phs) { mn = min(mn, v); }
		return mn;
	}

	int lastStoneWeightII(vector<int>& stones) {
		return check(stones);
	}
};

int main() {
	int n; cin >> n;
	vector<int> in(n); for (int i=0; i<n; ++i) { cin >> in[i]; }
	Solution sol;
	cout << sol.lastStoneWeightII(in) << endl;
	return 0;
}
