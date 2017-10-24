#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int eb = -5000000, es = 0, sz = prices.size();
		for (int i=0; i<sz; ++i) {
			int teb = -prices[i] + es;
			int tes = prices[i] + eb - fee;
			eb = max(teb, eb);
			es = max(es, tes);
		}

		return es;
	}
};

int main() {
	int n, f; cin >> n >> f;
	vector<int> p(n);
	for (int i=0; i<n; ++i) { cin >> p[i]; }
	Solution sol;
	cout << sol.maxProfit(p, f) << endl;
	return 0;
}
