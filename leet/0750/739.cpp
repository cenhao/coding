class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& t) {
		int sz = t.size();
		vector<int> ans(sz);
		vector<int> tm(101, -1);
		for (int i=sz-1; i>=0; --i) {
			int mn = -1;
			for (int j=t[i]+1; j<=100; ++j) {
				if (tm[j] >= 0 && (-1 == mn || tm[j] < mn)) {
					mn = tm[j];
				}
			}

			ans[i] = mn == -1 ? 0 : (mn - ans[i]);
			tm[t[i]] = i;
		}

		return ans;
	}
};
