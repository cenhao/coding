class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int len = s.length();

		int mx = 0;
		for (int i=0, last=0, cost=0; i<len; ++i) {
			cost += abs(s[i]-t[i]);
			while (last<=i && cost>maxCost) {
				cost -= abs(s[last]-t[last]);
				++last;
			}
			mx = max(mx, i-last+1);
		}

		return mx;
	}
};
