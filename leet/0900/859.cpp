class Solution {
public:
	bool buddyStrings(string a, string b) {
		if (a.length() != b.length()) { return false; }
		if (a == b) {
			unordered_set<char> hs;
			for (auto c: a) {
				if (hs.find(c) != hs.end()) { return true; }
				hs.insert(c);
			}
		} else {
			int cnt = 0, pos[2];
			for (int i=0; i<a.length(); ++i) {
				if (a[i] != b[i]) {
					if (cnt >= 2) { return false; }
					pos[cnt++] = i;
				}
			}
			if (cnt != 2) { return false; }
			swap(a[pos[0]], a[pos[1]]);
			return a == b;
		}
		return false;
	}
};
