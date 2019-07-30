class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		unordered_map<int, int> hm;
		for (auto &d: dominoes) {
			int a = d[0], b = d[1];
			if (a > b) { swap(a, b); }
			++hm[a*10 + b];
		}

		int ans = 0;
		for (auto &kvp: hm) {
			if (kvp.second <= 1) { continue; }
			int n = kvp.second;
			ans += n * (n-1) / 2;
		}
		return ans;
	}
};
