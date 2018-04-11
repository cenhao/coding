#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double largestSumOfAverages(vector<int>& a, int K) {
		int sz = a.size();
		const double EPS = 1e-7;
		vector<vector<double>> dp(sz+1, vector<double>(sz+1, -1));
		dp[0][0] = 0;
		for (int i=0; i<sz; ++i) {
			double sm = 0;
			for (int j=i; j>=0; --j) {
				sm += a[j];
				double avg = sm / double(i-j+1);
				for (int k=K-1; k>=0; --k) {
					if (dp[j][k] < -EPS) { continue; }
					double tmp = avg + dp[j][k];
					dp[i+1][k+1] = max(dp[i+1][k+1], tmp);
				}
			}
		}

		return dp[sz][K];
	}
};

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.largestSumOfAverages(a, k) << endl;
	return 0;
}
