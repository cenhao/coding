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
    bool canAttendMeetings(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), [] (const Interval &i1, const Interval &i2) {
			return (i1.start == i2.start) ? i1.end < i2.end : i1.start < i2.start;
		});

		bool ok = true, init = false;
		int last;
		for (auto &i: intervals) {
			if (!init || i.start>=last) {
				last = i.end;
				init = true;
			} else {
				ok = false;
				break;
			}
		}

		return ok;
    }
};
