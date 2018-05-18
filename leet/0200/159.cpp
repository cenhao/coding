class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		unordered_map<char, int> pm;
		int mx = 0, start = 0;
		for (int i=0; i<s.length(); ++i) {
			if (pm.find(s[i]) == pm.end()) {
				while (pm.size() > 1) {
					--pm[s[start]];
					if (pm[s[start]] == 0) { pm.erase(s[start]); }
					++start;
				}
			}
			++pm[s[i]];
			mx = max(mx, i-start+1);
		}
		return mx;
	}
};
