class Solution {
public:
	struct Pos { int p, d; };

	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<bool> vis(N, false);
		vector<int> mdist(N, -1);
		mdist[K-1] = 0;
		vector<vector<pair<int, int>>> dist(N);
		int sz = times.size();
		for (int i=0; i<sz; ++i) {
			dist[times[i][0]-1].push_back(make_pair(times[i][1]-1, times[i][2]));
		}
		auto cmp = [](const Pos &p1, const Pos &p2) {
			return p1.d > p2.d;
		};
		priority_queue<Pos, vector<Pos>, decltype(cmp)> pq(cmp);
		Pos tmp = {K-1, 0};
		pq.push(tmp);
		while (!pq.empty()) {
			tmp = pq.top(); pq.pop();
			if (vis[tmp.p]) { continue; }
			vis[tmp.p] = true;
			for (int i=0; i<dist[tmp.p].size(); ++i) {
				Pos tmp1 = { dist[tmp.p][i].first, dist[tmp.p][i].second+tmp.d };
				if (mdist[tmp1.p] >= 0 && tmp1.d >= mdist[tmp1.p]) { continue; }
				mdist[tmp1.p] = tmp1.d;
				pq.push(tmp1);
			}
		}

		int ans = 0;
		bool ok = true;
		for (auto d : mdist) {
			if (d < 0) {
				ok = false;
				break;
			}
			ans = max(d, ans);
		}
		return ok ? ans : -1;
	}
};
