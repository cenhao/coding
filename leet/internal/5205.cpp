class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> hm;
		for (auto a: arr) { ++hm[a]; }

		unordered_map<int, int> hm1;
		for (auto &kvp: hm) {
			int v = ++hm1[kvp.second];
			if (v > 1) { return false; }
		}
		return true;
	}
};
