class Solution {
public:
	vector<int> pourWater(vector<int>& h, int V, int K) {
		int sz = h.size();
		auto fcmp = [&h](int i1, int i2) {
			return h[i1] == h[i2] ? i1 < i2 : h[i1] > h[i2];
		};
		priority_queue<int, vector<int>, decltype(fcmp)> fq(fcmp);
		auto bcmp = [&h](int i1, int i2) {
			return h[i1] == h[i2] ? i1 > i2 : h[i1] > h[i2];
		};
		priority_queue<int, vector<int>, decltype(bcmp)> bq(bcmp);

		int fi = K-1, bi = K+1;
		for (int i=0; i<V; ++i) {
			while (fi >= 0 && h[fi] <= h[K] && (fq.empty() || h[fi] <= h[fq.top()])) {
				fq.push(fi--);
			}
			while (bi < sz && h[bi] <= h[K] && (bq.empty() || h[bi] <= h[bq.top()])) {
				bq.push(bi++);
			}
			int fh = 0x7fff0000, bh = 0x7fff0000;
			if (!fq.empty()) { fh = h[fq.top()]; }
			if (!bq.empty()) { bh = h[bq.top()]; }
			if (fh < h[K]) {
				int t = fq.top(); fq.pop();
				++h[t];
				fq.push(t);
			} else if (bh < h[K]) {
				int t = bq.top(); bq.pop();
				++h[t];
				bq.push(t);
			} else {
				++h[K];
			}
		}

		return h;
	}
};
