class Solution {
public:
	vector<int> shortestToChar(string s, char c) {
		int len = s.length();
		vector<int> ans(len, 200000);
		for (int i=0, last=-200000; i<len; ++i) {
			if (s[i] == c) {
				ans[i] = 0;
				for (int j=i-1; j>=0 && i-j<ans[j]; --j) {
					ans[j] = i-j;
				}
				last = i;
			} else {
				ans[i] = i - last;
			}
		}

		return ans;
	}
};
