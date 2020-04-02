class Solution {
public:
	vector<int> numSmallerByLeadingCount(vector<string>& queries, vector<string>& words) {
		map<int, int> hm;
		for (auto &w: words) {
			int mn = 0x7fffffff, cnt = 0;
			for (auto c: w) { if (mn > c) { mn = c; } }
			for (auto c: w) { if (c == mn) { ++cnt; } }
			++hm[cnt];
		}

		int sum = 0;
		for (auto it=hm.rbegin(); it!=hm.rend(); ++it) {
			int cur = it->second;
			it->second += sum;
			sum += cur;
		}

		vector<int> ans(queries.size());
		for (int i=0; i<queries.size(); ++i) {
			int mn = 0x7fffffff, cnt = 0;
			for (auto c: queries) { if (mn > c) { mn = c; } }
			for (auto c: queries) { if (c == mn) { ++cnt; } }
			auto it = hm.upper_bound(cnt);
			ans[i] = it == hm.end() ? 0 : it->second;
		}

		return ans;
	}
};
