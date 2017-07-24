class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		int sz = pairs.size();
		sort(pairs.begin(), pairs.end(), [](const vector<int> &v1, const vector<int> &v2) {
			return (v1[0] != v2[0]) ? (v1[0] < v2[0]) : (v1[1] < v2[1]);
		});

		vector<int> cnt(sz, 1);
		for (int i=0; i<sz; ++i) {
			for (int j=i-1; j>=0; --j) {
				if (pairs[i][0] > pairs[j][1]) { cnt[i] = max(cnt[i], cnt[j] + 1); }
			}
		}

		int mx = 0;
		for (int i=0; i<sz; ++i) { mx = max(mx, cnt[i]); }
		return mx;
	}
};
