class Solution {
public:
	int reachableNodes(vector<vector<int>>& edges, int M, int N) {
		vector<vector<pair<int, int>>> adj(N);
		for (auto &e: edges) {
			adj[e[0]].emplace_back(e[1], e[2]);
			adj[e[1]].emplace_back(e[0], e[2]);
		}
		vector<int> cnt(N, -1);
		cnt[0] = M;
		vector<unordered_map<int, int>> reach(N);
		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.second < p2.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		pq.emplace(0, M);
		int ans = 0;
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			int idx = cur.first, r = cur.second;
			if (r < cnt[idx]) { continue; }
			++ans;
			for (auto &pv: adj[idx]) {
				int v = pv.first, step = pv.second;
				if (r-step-1 > cnt[v]) {
					pq.emplace(v, r-step-1);
					cnt[v] = r-step-1;
				}
				int fr = reach[idx][v], tr = reach[v][idx];
				if (r <= fr) { continue; }
				int add = min(max(0, step-fr-tr), r-fr);
				ans += add;
				reach[idx][v] = min(r, step);
			}
		}

		return ans;
	}
};
