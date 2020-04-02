class Solution {
public:
	string smallestStringWithSwaps(string str, vector<vector<int>>& pairs) {
		int sz = str.length();
		vector<int> f(sz);
		function<int(int)> find;
		find = [&](int x) {
			return f[x] = f[x]==x ? f[x] : find(f[x]);
		};
		for (int i=0; i<sz; ++i) { f[i] = i; }
		for (auto &p: pairs) {
			int f1 = find(p[0]), f2 = find(p[1]);
			f[f1] = f2;
		}
		vector<int> gid(sz);
		for (int i=0; i<sz; ++i) { gid[i] = find(i); }

		vector<string> g(sz);
		for (int i=0; i<sz; ++i) { g[gid[i]] += str[i]; }
		for (int i=0; i<sz; ++i) { sort(g[i].begin(), g[i].end()); }
		vector<int> nxt(sz, 0);
		string ans;
		for (int i=0; i<sz; ++i) { ans += g[gid[i]][nxt[gid[i]]++]; }
		return ans;
	}
};
