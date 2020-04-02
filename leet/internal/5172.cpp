#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string largestMultipleOfThree(vector<int>& digits) {
		int zcnt = 0;
		vector<int> nd;
		for (int i=0; i<digits.size(); ++i) {
			if (digits[i] != 0) {
				nd.push_back(digits[i]);
			} else {
				++zcnt;
			}
		}

		sort(nd.begin(), nd.end(), greater<int>());
		int sz = nd.size();
		vector<bool> ready = { true, false, false };
		vector<string> mxd(3), tmp(3);
		for (int i=0; i<sz; ++i) {
			int mod = nd[i] % 3;
			for (int j=0; j<3; ++j) {
				int idx = (j+mod) % 3;
				if (ready[j]) {
					tmp[idx] = mxd[j] + char(nd[i] + '0');
				} else {
					tmp[idx] = "#";
				}
			}
			for (int j=0; j<3; ++j) {
				if (tmp[j][0] == '#') { continue; }
				if (!ready[j] || tmp[j].length()>mxd[j].length() ||
					(tmp[j].length()==mxd[j].length() && tmp[j]>mxd[j])) {
					mxd[j] = tmp[j];
					ready[j] = true;
				}
			}
		}

		string ans = mxd[0];
		zcnt = (ans.length()>0) ? zcnt : min(zcnt, 1);
		for (int i=0; i<zcnt; ++i) { ans += '0'; }
		return ans;
	}
};

int main() {
	vector<int> d = { 8, 7, 6, 1, 0 };
	Solution sol;
	cout << sol.largestMultipleOfThree(d) << endl;
	return 0;
}
