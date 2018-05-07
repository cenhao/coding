class Solution {
public:
	int find(int x, vector<int> &f) {
		if (f[x] != f[f[x]]) {
			f[x] = find(f[x], f);
		}
		return f[x];
	}
	bool validTree(int n, vector<pair<int, int>>& edges) {
		vector<int> f(n);
		for (int i=0; i<n; ++i) { f[i] = i; }
		for (auto &e: edges) {
			int p1 = find(e.first, f), p2 = find(e.second, f);
			if (p1 == p2) { return false; }
			f[p2] = p1;
		}
		int last = -1;
		for (auto p: f) {
			int rp = find(p, f);
			if (last != -1 && rp != last) {
				return false;
			}
			last = rp;
		}
		return true;
	}
};
