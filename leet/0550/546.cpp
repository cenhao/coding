#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dp[101][101][101]; // MAXN == 100

	struct BoxState {
		int val, cnt;
	};

	int dfs(int l, int r, int pk, const vector<BoxState> &vec) {
		if (r < l) { return 0; }
		if (dp[l][r][pk] >= 0) { return dp[l][r][pk]; }
		dp[l][r][pk] = dfs(l, r-1, 0, vec) + (pk + vec[r].cnt) * (pk + vec[r].cnt);

		for (int i=l; i<r; ++i) {
			if (vec[i].val == vec[r].val) {
				dp[l][r][pk] = max(dp[l][r][pk], dfs(l, i-1, 0, vec) + dfs(i+1, r, pk+vec[i].cnt, vec));
			}
		}

		return dp[l][r][pk];
	}

	int removeBoxes(vector<int>& boxes) {
		if (boxes.size() == 0) { return 0; }

		memset(dp, -1, sizeof(dp));

		vector<BoxState> vec;
		BoxState bs = { boxes[0], 0 };
		vec.push_back(bs);

		for (int i=0; i<boxes.size(); ++i) {
			if (boxes[i] != vec[vec.size()-1].val) {
				bs.val = boxes[i];
				vec.push_back(bs);
			}

			++vec[vec.size()-1].cnt;
		}

		return dfs(0, vec.size()-1, 0, vec);
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.removeBoxes(v) << endl;
	return 0;
}
