#include <bits/stdc++.h>
using namespace std;
class Solution {
	struct V { int b, t, a; };
public:
	int rectangleArea(vector<vector<int>>& rectangles) {
		map<int, vector<V>> hm;
		for (auto rec: rectangles) {
			hm[rec[0]].push_back({rec[1], rec[3], 0});
			hm[rec[2]].push_back({rec[1], rec[3], 1});
		}

		vector<V> rngs;
		int64_t len = 0, prevx = 0;
		int64_t ans = 0;
		const int MOD = 1000000007;
		for (auto &kvp: hm) {
			int64_t add = (kvp.first-prevx) * len;
			prevx = kvp.first;
			ans = (ans + add) % MOD;
			for (auto &v: kvp.second) {
				bool found = false;
				for (int i=0; i<rngs.size(); ++i) {
					if (rngs[i].b == v.b && rngs[i].t == v.t) {
						if (v.a) {
							--rngs[i].a;
						} else {
							++rngs[i].a;
						}
						found = true;
					}
				}
				if (!found) {
					rngs.push_back({v.b, v.t, 1});
				}
			}
			vector<V> tmp;
			for (auto &r: rngs) {
				if (r.a > 0) { tmp.push_back(r); }
			}
			rngs = move(tmp);
			sort(rngs.begin(), rngs.end(), [](const V &v1, const V &v2) {
				return v1.b == v2.b ? v1.t > v2.t : v1.b < v2.b;
			});
			len = 0;
			int64_t last = -1;
			for (int i=0; i<rngs.size(); ++i) {
				if (rngs[i].b >= last) {
					len += rngs[i].t - rngs[i].b;
					last = rngs[i].t;
				} else if (rngs[i].t >= last) {
					len += rngs[i].t - last;
					last = rngs[i].t;
				}
			}
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> rect(n, vector<int>(4));
	for (int i=0; i<n; ++i) {
		cin >> rect[i][0] >> rect[i][1] >> rect[i][2] >> rect[i][3];
	}
	Solution sol;
	cout << sol.rectangleArea(rect) << endl;
}
