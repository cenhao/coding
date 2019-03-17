class Solution {
public:
	int largestSumAfterKNegations(vector<int>& a, int k) {
		sort(a.begin(), a.end());
		int sm = 0;
		for (int i=0; i<a.size() && k>0; ++i) {
			if (a[i] < 0) {
				a[i] = -a[i];
				--k;
			}
		}

		k %= 2;
		sort(a.begin(), a.end());
		if (k > 0) { a[0] = -a[0]; }
		for (auto v: a) { sm += v; }
		return sm;
	}
};
