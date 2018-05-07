class Solution {
public:
	int hIndex(vector<int>& citations) {
		int sz = citations.size();
		vector<int> cnt(sz+1, 0);
		for (auto c: citations) {
			if (c <= sz) { ++cnt[c]; }
		}

		int sm = 0, ans = 0;
		for (int i=0; i<=sz; ++i) {
			if (i <= sz-sm) { ans = i; }
			sm += cnt[i];
		}

		return ans;
	}
};
