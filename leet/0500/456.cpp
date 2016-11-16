#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
	public:
	bool find132pattern(vector<int> &nums) {
		if (nums.size() < 3) { return false; }
		int mn = nums[0];
		map<int, int> right;
		for (int i=2, end=nums.size(); i<end; ++i) {
			++right[nums[i]];
		}

		for (int i=1, end=nums.size()-1; i<end; ++i) {
			auto it = right.upper_bound(mn);
			if (it != right.end()) {
				if ((it->first) < nums[i] && mn < (it->first)) { return true; }
			}

			it = right.find(nums[i+1]);
			if (it->second > 1) {
				--it->second;
			} else {
				right.erase(it);
			}

			mn = min(mn, nums[i]);
		}

		return false;
	}
};
/*
class Solution {
	public:
		bool find132pattern(vector<int>& nums) {
			const double EPS = 1e-6;
			if (nums.size() < 3) { return false; }
			int rmqDepth = int(log2(nums.size()-1) + EPS) + 1;
			vector<vector<int> > rmx(rmqDepth, vector<int>(nums.size()));
			vector<vector<int> > rmxi(rmqDepth, vector<int>(nums.size()));
			vector<vector<int> > rmn(rmqDepth, vector<int>(nums.size()));
			vector<vector<int> > rmni(rmqDepth, vector<int>(nums.size()));

			for (int i=0, end=nums.size(); i<end; ++i) {
				rmx[0][i] = rmn[0][i] = nums[i];
				rmxi[0][i] = rmni[0][i] = i;
			}

			for (int pw=1, end=nums.size(); (1<<pw) < end; ++pw) {
				int len = 1 << pw, sub = 1 << (pw - 1);
				for (int i=end-len; i>=0; --i) {
					if (rmx[pw-1][i] > rmx[pw-1][i+sub]) {
						rmx[pw][i] = rmx[pw-1][i];
						rmxi[pw][i] = rmxi[pw-1][i];
					} else {
						rmx[pw][i] = rmx[pw-1][i+sub];
						rmxi[pw][i] = rmxi[pw-1][i+sub];
					}
					if (rmn[pw-1][i] < rmn[pw-1][i+sub]) {
						rmn[pw][i] = rmn[pw-1][i];
						rmni[pw][i] = rmni[pw-1][i];
					} else {
						rmn[pw][i] = rmn[pw-1][i+sub];
						rmni[pw][i] = rmni[pw-1][i+sub];
					}
				}
			}

			return find(0, nums.size()-1, rmx, rmxi, rmn, rmni);
		}

		bool find(int start, int end,
				  const vector<vector<int> > &rmx, const vector<vector<int> > &rmxi,
				  const vector<vector<int> > &rmn, const vector<vector<int> > &rmni) {
			if (end - start < 2) { return false; }

			int mx, mxi;
			int submx, mn, ti;
			findMax(start, end, rmx, rmxi, mx, mxi);
			if (mxi != end && mxi != start) {
				findMax(mxi+1, end, rmx, rmxi, submx, ti);
				findMin(start, mxi-1, rmn, rmni, mn, ti);
				if (submx > mn && mx > submx) {
					return true;
				}
			}

			if (mxi != end && find(mxi+1, end, rmx, rmxi, rmn, rmni)) {
				return true;
			}
			if (mxi != start && find(start, mxi-1, rmx, rmxi, rmn, rmni)) {
				return true;
			}

			return false;
		}

		void findMax(int start, int end,
				  const vector<vector<int> > &rmx, const vector<vector<int> > &rmxi,
				  int &mx, int &mxi) {
			if (start == end) {
				mx = rmx[0][start];
				mxi = start;
				return;
			}

			int base = int(log2(end-start)+(1e-6));
			int len = 1 << base;

			if (rmx[base][start] > rmx[base][end-len+1]) {
				mx = rmx[base][start];
				mxi = rmxi[base][start];
			} else {
				mx = rmx[base][end-len+1];
				mxi = rmxi[base][end-len+1];
			}
		}

		void findMin(int start, int end,
				  const vector<vector<int> > &rmn, const vector<vector<int> > &rmni,
				  int &mn, int &mni) {
			if (start == end) {
				mn = rmn[0][start];
				mni = start;
				return;
			}

			int base = int(log2(end-start)+(1e-6));
			int len = 1 << base;

			if (rmn[base][start] < rmn[base][end-len+1]) {
				mn = rmn[base][start];
				mni = rmni[base][start];
			} else {
				mn = rmn[base][end-len+1];
				mni = rmni[base][end-len+1];
			}
		}
};
*/

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }

	Solution sol;
	cout << sol.find132pattern(v) << endl;

	return 0;
}
