#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
	public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<int> zero(strs.size(), 0);
		vector<int> one(strs.size(), 0);
		for (int i=0, end=strs.size(); i<end; ++i) {
			for (auto c : strs[i]) {
				if (c == '0') { ++zero[i]; }
				else { ++one[i]; }
			}
		}

		vector<vector<int>> mx(n+1, vector<int>(m+1, 0));
		for (int i=0, end=strs.size(); i<end; ++i) {
			for (int i1=n; i1>=one[i]; --i1) {
				for (int i2=m; i2>=zero[i]; --i2) {
					mx[i1][i2] = max(mx[i1][i2], mx[i1-one[i]][i2-zero[i]] + 1);
				}
			}
		}

		return mx[n][m];
	}
};

int main() {
	int k; cin >> k;
	vector<string> strs(k);
	for (int i=0; i<k; ++i) { cin >> strs[i]; }
	int m, n; cin >> m >> n;
	Solution sol;
	cout << sol.findMaxForm(strs, m, n) << endl;
	return 0;
}
