class Solution {
public:
	struct Edge { int v, p; };
	struct Stop { int p, cnt, loc; };
	int findCheapestPrice(int n, vector<vector<int>> &f, int src, int dst, int k) {
		vector<vector<Edge>> adj(n);
		vector<vector<int>> mncost(n, vector<int>(k+2, 0x7fffffff));
		for (auto &t : f) { adj[t[0]].push_back({ t[1], t[2] }); }
		auto cmp = [](const Stop &s1, const Stop &s2) {
			return s1.p == s2.p ? (s1.cnt > s2.cnt) : (s1.p > s2.p);
		};
		priority_queue<Stop, vector<Stop>, decltype(cmp)> pq(cmp);
		pq.push({ 0, 0, src });
		mncost[src][0] = 0;
		int mn = -1;

		while (!pq.empty()) {
			Stop tmp = pq.top(); pq.pop();
			if (tmp.p > mncost[tmp.loc][tmp.cnt]) { continue; }
			if (tmp.loc == dst) {
				if (mn == -1 || tmp.p < mn) { mn = tmp.p; }
			}
			for (auto &e : adj[tmp.loc]) {
				Stop tmp1 = { tmp.p+e.p, tmp.cnt+1, e.v };
				if (tmp1.cnt<=k+1 && mncost[tmp1.loc][tmp1.cnt] > tmp1.p) {
					mncost[tmp1.loc][tmp1.cnt] = tmp1.p;
					pq.push(tmp1);
				}
			}
		}

		return mn;
	}
};
