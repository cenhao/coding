#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool possible(const vector<int> &idx, const vector<int> &p, const vector<int> &c, int k, int w, int64_t target) {
		int cur = 0, pick = 0;
		int64_t wsum = w;
		priority_queue<int> pq;
		while (pick < k) {
			for ( ; cur<idx.size() && c[idx[cur]]<=wsum; ++cur) {
				pq.push(p[idx[cur]]);
			}

			if (pq.empty()) { break; }
			wsum += pq.top(); pq.pop();
			++pick;
		}

		return wsum >= target;
	}

	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		vector<int> idx(Profits.size());
		for (int i=0; i<idx.size(); ++i) { idx[i] = i; }
		sort(idx.begin(), idx.end(), [&](const int a, const int b) {
			return Capital[a] < Capital[b];
		});

		int64_t l = 0, r = 0x7fffffff, m;
		while (l <= r) {
			m = (l + r) / 2;

			if (possible(idx, Profits, Capital, k, W, m)) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return r;
	}
};
