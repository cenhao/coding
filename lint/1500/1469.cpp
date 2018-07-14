class Solution {
public:
    /**
     * @param n: The number of nodes
     * @param starts: One point of the edge
     * @param ends: Another point of the edge
     * @param lens: The length of the edge
     * @return: Return the length of longest path on the tree.
     */
    int longestPath(int n, vector<int> &starts, vector<int> &ends, vector<int> &lens) {
		vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
		for (int i=0; i<starts.size(); ++i) {
			adj[starts[i]].emplace_back(ends[i], lens[i]);
			adj[ends[i]].emplace_back(starts[i], lens[i]);
		}

		int ans = 0;
		function<int(int, int)> traverse;
		traverse = [&](int cur, int par) {
			int mx = 0, smx = 0;
			for (auto &p: adj[cur]) {
				if (p.first == par) { continue; }
				int d = traverse(p.first, cur) + p.second;
				if (d >= mx) {
					smx = mx; mx = d;
				} else if (d > smx) {
					smx = d;
				}
			}

			ans = max(ans, mx + smx);
			return mx;
		};

		traverse(0, -1);
		return ans;
    }
};
