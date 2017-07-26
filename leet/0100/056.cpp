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
    vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2) {
			return (i1.start != i2.start) ? (i1.start < i2.start) : (i1.end < i2.end);
		});

		vector<Interval> ans;
		int last = -0x7fffffff;
		for (const auto &i : intervals) {
			if (i.start > last) {
				last = i.end;
				ans.push_back(i);
			} else {
				ans[ans.size()-1].end = last = max(last, i.end);
			}
		}

		return ans;
    }
};
