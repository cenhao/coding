class Solution {
public:
	int findLucky(vector<int>& arr) {
		unordered_map<int, int> hm;
		for (auto a: arr) { ++hm[a]; }
		int mx = -1;
		for (auto &kvp: hm) {
			if (kvp.first == kvp.second) {
				mx = max(mx, kvp.second);
			}
		}

		return mx;
	}
};
