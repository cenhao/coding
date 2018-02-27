class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> l, r, vis;
		int mx = 0;
		for (auto n : nums) {
			if (vis.find(n) != vis.end()) { continue; }
			vis[n] = 1;
			auto rit = r.find(n+1);
			auto lit = l.find(n-1);
			int le = n, re = n;
			if (rit != r.end()) { re = rit->second; }
			if (lit != l.end()) { le = lit->second; }
			l[le] = l[re] = le;
			r[le] = r[re] = re;
			mx = max(re-le+1, mx);
		}

		return mx;
	}
};
