/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int sz = intervals.size();
		vector<Interval> ans;
		int pos = 0;
		while (pos < sz && intervals[pos].end < newInterval.start) {
				ans.push_back(intervals[pos++]);
		}

		if (pos < sz && intervals[pos].start < newInterval.start) {
			swap(newInterval, intervals[pos]);
		}
		ans.push_back(newInterval);

		while (pos < sz) {
			int idx = ans.size()-1;
			if (intervals[pos].start <= ans[idx].end) {
				ans[idx].end = max(ans[idx].end, intervals[pos].end);
			} else {
				ans.push_back(intervals[pos]);
			}

			++pos;
		}

		return ans;
    }
};
