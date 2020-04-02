class Solution {
public:
	int balancedStringSplit(string s) {
		int ans = 0, rcnt = 0;
		for (auto c: s) {
			rcnt += (c == 'R') ? 1 : -1;
			if (rcnt == 0) { ++ans; }
		}

		return ans;
	}
};
