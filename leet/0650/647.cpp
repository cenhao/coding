class Solution {
public:
	int countSubstrings(string s) {
		int len = s.length();
		vector<vector<bool>> is_pa(len, vector<bool>(len+1, false));
		for (int i=0; i<len; ++i) { is_pa[i][0] = is_pa[i][1] = true; }
		int ans = len;
		for (int i=2; i<=len; ++i) {
			for (int j=0; j+i<=len; ++j) {
				if (s[j] == s[j+i-1] && is_pa[j+1][i-2]) {
					is_pa[j][i] = true;
					++ans;
				}
			}
		}

		return ans;
	}
};
