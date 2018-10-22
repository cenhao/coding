class Solution {
	struct Pos { int idx, len, w; };
public:
	vector<int> cheapestJump(vector<int>& a, int b) {
		int sz = a.size();
		vector<int> from(sz, -1), ans;

		vector<Pos> q(sz);
		q[0] = { 0, 1, a[0] };
		int h = 0, r = 1;

		from[0] = 0;

		for (int i=1; i<sz; ++i) {
			if (a[i] == -1) { continue; }
			while (h!=r && q[h].idx+b<i) { ++h; }
			if (h == r) { break; }

			from[i] = q[h].idx + 1;
			int w = a[i] + q[h].w, len = q[h].len+1;
			while (h!=r && (w<q[r-1].w || (w==q[r-1].w && len>q[r-1].len))) { --r; }
			q[r++] = { i, len, w };
		}

		if (from[sz-1] != -1) {
			for (int i=sz-1; i>=0; i=from[i]-1) {
				ans.push_back(i+1);
			}
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};
