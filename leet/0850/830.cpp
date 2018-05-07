class Solution {
public:
	vector<vector<int>> largeGroupPositions(string s) {
		int len = s.length(), cnt = 0;
		char last = 0;
		vector<vector<int>> ans;
		for (int i=0; i<=len; ++i) {
			if (i==len || s[i]!=last) {
				if (cnt >= 3) { ans.push_back({i-cnt, i-1}); }
				if (i == len) { break; }
				cnt = 0;
				last = s[i];
			}
			++cnt;
		}

		return ans;
	}
};
