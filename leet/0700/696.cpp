class Solution {
public:
	int countBinarySubstrings(string s) {
		vector<int> cnt;
		int last = 0;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] != last) {
				last = s[i];
				cnt.push_back(0);
			}
			++cnt[cnt.size()-1];
		}

		int ans = 0;
		for (int i=1; i<cnt.size(); ++i) {
			ans += min(cnt[i], cnt[i-1]);
		}

		return ans;
	}
};
