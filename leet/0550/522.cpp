#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		int mx = -1;
		for (int i=0; i<strs.size(); ++i) {
			if (strs[i].length() == 0) { continue; }
			bool ok = true;
			for (int j=0; j<strs.size(); ++j) {
				if (i == j || strs[i].length() > strs[j].length()) { continue; }

				int iidx = 0;
				for (int k=0; k<strs[j].length(); ++k) {
					if (strs[i][iidx] == strs[j][k]) {
						if (++iidx >= strs[i].length()) { break; }
					}
				}
				
				if (iidx >= strs[i].length()) {
					ok = false;
					break;
				}
			}

			if (ok) { mx = max(mx, (int)strs[i].length()); }
		}

		return mx;
	}
};

int main() {
	int n; cin >> n;
	vector<string> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.findLUSlength(v) << endl;
	return 0;
}
