class Solution {
public:
	vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
		int len = s.length();
		vector<vector<int>> cnt(len+1, vector<int>(26, 0));
		for (int i=0; i<len; ++i) {
			for (int j=0; j<26; ++j) { cnt[i+1][j] = cnt[i][j]; }
			++cnt[i+1][s[i]-'a'];
		}

		vector<bool> ans;
		for (auto &q: queries) {
			int remainder = 0;
			for (int i=0; i<26; ++i) {
				int scnt = cnt[q[1]+1][i] - cnt[q[0]][i];
				remainder += scnt % 2;
			}

			int slen = q[1] - q[0] + 1;
			if (slen & 1) { --remainder; }
			ans.emplace_back(remainder/2 <=q[2]);
		}

		return ans;
	}
};
