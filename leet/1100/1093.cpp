#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<double> sampleStats(vector<int>& count) {
		double sm = 0.0;
		int sz = count.size();
		int cnt = 0, mx = -1, mn = 300, mxf = 0, mxfv;
		for (int i=0; i<sz; ++i) {
			int64_t v = i;
			sm += v * count[i];
			if (count[i] > 0) {
				mx = max(mx, i);
				mn = min(mn, i);
			}
			if (count[i] > mxf) {
				mxf = count[i];
				mxfv = i;
			}
			cnt += count[i];
		}

		int l, r;
		if (cnt % 2 == 0) {
			l = cnt / 2;
			r = l + 1;
		} else {
			l = r = (cnt / 2) + 1;
		}

		int ccnt = 0, medl = -1, medr = -1;
		for (int i=0; i<sz; ++i) {
			if (count[i] <= 0) { continue; }
			ccnt += count[i];
			if (ccnt >= l && medl == -1) { medl = i; }
			if (ccnt >= r && medr == -1) { medr = i; break; }
		}

		vector<double> ret { double(mn), double(mx), sm/cnt, (medl+medr)/2.0, double(mxfv) };
		return ret;
	}
};

int main() {
	vector<int> in { 0, 1, 3, 4 };
	Solution sol;
	sol.sampleStats(in);
	return 0;
}
