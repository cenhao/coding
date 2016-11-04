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
		int eraseOverlapIntervals(vector<Interval>& intervals) {
			if (intervals.size() == 0) { return 0; }

			sort(intervals.begin(), intervals.end(), cmp);
			int mn = intervals[0].end, cnt = 0;
			for (int i=1, end=intervals.size(); i<end; ++i) {
				if (intervals[i].start >= mn) {
					mn = intervals[i].end;
				} else {
					++cnt;
					mn = min(intervals[i].end, mn);
				}
			}

			return cnt;
		}

		static bool cmp(const Interval& itv1, const Interval itv2) {
			if (itv1.start == itv2.start) {
				return itv1.end < itv2.end;
			}

			return itv1.start < itv2.start;
		}
};
