#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		struct Itv {
			int idx;
			Interval data;
		};

		vector<int> findRightInterval(vector<Interval>& intervals) {
			vector<Itv> itvs;
			for (int i=0, end=intervals.size(); i<end; ++i) {
				Itv itv; itv.idx = i; itv.data = intervals[i];
				itvs.push_back(itv);
			}

			sort(itvs.begin(), itvs.end(), cmp);
			vector<int> result(intervals.size());

			for (int i=0, end=itvs.size(); i<end; ++i) {
				int l=i+1, r=end-1, m;
				while (l <= r) {
					m = (l + r) >> 1;
					if (itvs[m].data.start < itvs[i].data.end) {
						l = m + 1;
					} else {
						r = m - 1;
					}
				}

				++r;
				result[itvs[i].idx] = (r <= i || r >= end) ? -1 : itvs[r].idx;
			}

			return result;
		}

		static bool cmp(const Itv &itv1, const Itv &itv2) {
			if (itv1.data.start == itv2.data.start) {
				return itv1.idx < itv2.idx;
			}

			return itv1.data.start < itv2.data.start;
		}
};

int main() {
	int n; cin >> n;
	vector<Interval> itvs;
	for (int i=0; i<n; ++i) {
		int s, e; cin >> s >> e;
		Interval itv(s, e);
		itvs.push_back(itv);
	}

	Solution sol;
	vector<int> result = sol.findRightInterval(itvs);
	for (int i=0; i<n; ++i) {
		cout << result[i] << endl;
	}

	return 0;
}
