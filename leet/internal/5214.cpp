class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		unordered_map<int, int> hm;
		for (auto a: arr) {
			int pv = a - difference;
			auto it = hm.find(pv);
			int mx = (it==hm.end() ? 0 : it->second) + 1;
			it = hm.find(a);
			if (it==hm.end() || it->second<mx) { hm[a] = mx; }
		}

		int mx = 0;
		for (auto &kvp: hm) {
			mx = max(mx, kvp.second);
		}
		return mx;
	}
};
