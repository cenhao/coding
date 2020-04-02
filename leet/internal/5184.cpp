#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
		sort(arr2.begin(), arr2.end());
		vector<int> arr3;
		for (int i=0; i<arr2.size(); ++i) {
			if (arr3.empty() || arr2[i]!=arr3[arr3.size()-1]) {
				arr3.push_back(arr2[i]);
			}
		}
		int sz1 = arr1.size(), sz3 = arr3.size(), inf = 1000000;
		vector<vector<int>> dp(sz1, vector<int>(sz3+1, inf));

		for (int i=0; i<sz3; ++i) { dp[0][i] = 1; }
		dp[0][sz3] = 0;

		for (int i=1; i<sz1; ++i) {
			int mn = inf;
			for (int j=0; j<sz3; ++j) {
				if (arr3[j] > arr1[i-1]) { mn = min(mn, dp[i-1][sz3]); }
				dp[i][j] = mn + 1;
				mn = min(mn, dp[i-1][j]);
			}
			for (int j=0; j<sz3 && arr3[j]<arr1[i]; ++j) {
				dp[i][sz3] = min(dp[i][sz3], dp[i-1][j]);
			}
			if (arr1[i] > arr1[i-1]) {
				dp[i][sz3] = min(dp[i][sz3], dp[i-1][sz3]);
			}
		}

		int mn = inf;
		for (int i=0; i<=sz3; ++i) { mn = min(mn, dp[sz1-1][i]); }
		if (mn >= inf) { mn = -1; }
		return mn;
	}
};

int main() {
	int n; cin >> n;
	vector<int> a1(n);
	for (int i=0; i<n; ++i) { cin >> a1[i]; }
	cin >> n;
	vector<int> a2(n);
	for (int i=0; i<n; ++i) { cin >> a2[i]; }
	Solution sol;
	cout << sol.makeArrayIncreasing(a1, a2) << endl;
	return 0;
}
