class Solution {
public:
	int shortestSubarray(vector<int>& a, int K) {
		int sz = a.size();
		vector<pair<int, int>> q(sz+10);
		int h = 0, t = 1;
		q[0] = make_pair(-1, 0);
		int sm = 0, mn = -1;
		for (int i=0; i<sz; ++i) {
			sm += a[i];
			int l = h, r = t-1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (sm-q[m].second >= K) {
					l = m + 1;
				} else {
					r = m - 1;
				}
			}

			if (r >= h) {
				int tmp = i - q[r].first;
				if (mn==-1 || tmp<mn) { mn = tmp; }
			}

			while (t!=h && sm<=q[t-1].second) { --t; }
			q[t++] = make_pair(i, sm);
		}

		return mn;
	}
};
