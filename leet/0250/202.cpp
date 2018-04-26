class Solution {
public:
	bool isHappy(int n, unordered_set<int> &hs) {
		if (n == 1) {
			return true;
		}
		if (hs.find(n) != hs.end()) { return false; }
		hs.insert(n);
		string s = to_string(n);
		int v = 0;
		for (auto c: s) { v += (c-'0') * (c-'0'); }
		return isHappy(v, hs);
	}
	bool isHappy(int n) {
		unordered_set<int> hs;
		return isHappy(n, hs);
	}
};
