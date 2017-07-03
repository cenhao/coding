#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct PQI {
		int v, id;
		bool operator < (const PQI &pqi) const {
			return v > pqi.v;
		}
	};
	vector<int> smallestRange(vector<vector<int>>& nums) {
		int nsz = nums.size();
		vector<int> cnt(nsz, 0);
		vector<int> idx(nsz, 0);
		vector<int> rear(nsz, 0);
		auto cmp = [&] (const int &a, const int &b) {
			return nums[a][idx[a]] > nums[b][idx[b]];
		};
		priority_queue<PQI> pq;
		queue<int> q;
		for (int i=0; i<nsz; ++i) {
			PQI tmp = { nums[i][0], i };
			pq.push(tmp);
		}
		int mn = -1;
		bool first = true;
		int h, r, inc = 0;
		vector<int> ans(2);
		while (!pq.empty()) {
			if (first) {
				PQI tmp = pq.top(); pq.pop();
				h = r = tmp.id;
				first = false;
			} else {
				PQI tmp = pq.top(); pq.pop();
				r = tmp.id;
			}
			q.push(r);
			++idx[r];
			++cnt[r];
			if (cnt[r] == 1) { ++inc; }
			if (idx[r] < nums[r].size()) {
				PQI tmp = { nums[r][idx[r]], r };
				pq.push(tmp);
			}
			while (cnt[h] > 1) {
				--cnt[h];
				++rear[h];
				q.pop(); h = q.front();
			}

			if (inc == nsz) {
				int tmp = nums[r][idx[r]-1] - nums[h][rear[h]];
				if (mn == -1 || tmp < mn) {
					mn = tmp;
					ans[0] = nums[h][rear[h]];
					ans[1] = nums[r][idx[r]-1];
				}
			}
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> nums(n);
	for (int i=0; i<n; ++i) {
		int m; cin >> m;
		int v;
		for (int j=0; j<m; ++j) {
			cin >> v;
			nums[i].push_back(v);
		}
	}

	Solution sol;
	vector<int> ans = sol.smallestRange(nums);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}
