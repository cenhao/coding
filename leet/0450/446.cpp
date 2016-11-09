/*
 * This is a good problem.
 * so dp[i][j] means using the i-th element, to form a subsequence (l>1) with j as the difference
 * between consecutive elements, # of solution
 * dp[i][j] = sum(dp[k][j]+1), for those A[i]-A[k] = j. If A[i]-A[K] == j, then i gets all the
 * solutions from k, and the `+1` is for the connection between i and k, i.e., the {A[k], A[i]}.
 * As a subsequence does not count, so eventually the count should - i (0-index) for every subsequence
 * with only two elements.
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		int numberOfArithmeticSlices(vector<int>& A) {
			vector<unordered_map<long long, int> > dp(A.size(), unordered_map<long long, int>());
			int sum = 0;
			for (int i=0, end=A.size(); i<end; ++i) {
				for (int j=i-1; j>=0; --j) {
					long long d = A[i];
					d = d - A[j];

					auto it = dp[j].find(d);
					int v = (it == dp[j].end()) ? 1 : it->second+1;
					dp[i][d] += v;
				}

				for (auto &p: dp[i]) { sum += p.second; }
				sum -= i;
			}

			return sum;
		}
};

int main() {
	int n; cin >> n;
	vector<int> A;
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		A.push_back(a);
	}

	Solution sol;
	cout << sol.numberOfArithmeticSlices(A) << endl;

	return 0;
}
