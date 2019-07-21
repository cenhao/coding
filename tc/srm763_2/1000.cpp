#include <bits/stdc++.h>
using namespace std;

class ETSums {
	const int mod = 1000000007;
	int64_t qpow(int64_t v, int p) {
		int64_t ret = 1, base = v;
		while (p > 0) {
			if (p & 1) { ret = (ret * base) % mod; }
			base = (base * base) % mod;
			p >>= 1;
		}
		return ret;
	}

public:
	int findSumOfETSums(int n, vector<int> parent, vector <int> cost, int d, int seed, int MX) {
		vector<int64_t> a(2*n);
		a[0] = seed;
		for (int i=1; i<2*n; ++i) { a[i] = (a[i-1] * 1103515245 + 12345) % 2147483648; }
		for (int i=parent.size(); i<n; ++i) { parent.push_back((a[i] % min(i, d)) + i - min(i, d)); }
		for (int i=cost.size(); i<n; ++i) { cost.push_back(a[n+i] % MX); }

		vector<vector<int>> chd(n, vector<int>());
		for (int i=1; i<n; ++i) { chd[parent[i]].push_back(i); }

		int t = 0;
		function<int64_t(int,int)> dfs = [&](int cur, int d) {
			int ct = ++t;
			int64_t v = ((cost[cur] * qpow(d, t)) % mod) % mod;
			int64_t ret = 0;
			for (auto c: chd[cur]) {
				ret = (ret + dfs(c, d+1)) % mod;
			}

			if (d == 1) {
				ret = (ret + ((v * (t-ct+1)) % mod)) % mod;
			} else if (d != 0) {
				int64_t tmp = (v * ((qpow(d, t-ct+1) - 1 + mod) % mod)) % mod;
				int64_t inv = qpow(d-1, mod-2);
				ret = (ret + ((tmp*inv) % mod)) % mod;
			}

			return ret;
		};

		int ret = dfs(0, 0);
		return ret;
	}
};

int main() {
	ETSums sol;
	//cout << sol.findSumOfETSums(5, {-1,0,0,1,3}, {5,0,3,2,3}, 1, 0, 6) << endl;
	//cout << sol.findSumOfETSums(100000, {-1,0,0,0}, {4, 7}, 1, 0, 1000000000) << endl;
	cout << sol.findSumOfETSums(7, {-1}, {}, 190629, 190629, 1000000000) << endl;
	return 0;
}
