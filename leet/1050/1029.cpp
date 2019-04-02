class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& a) {
		int sz = a.size(), r = 0;
		vector<bool> ans(sz, false);
		for (int i=0; i<sz; ++i) {
			r = ((r * 2) % 5 + a[i]) % 5;
			ans[i] = r == 0;
		}
		return ans;
	}
};
