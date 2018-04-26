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
    int minMeetingRooms(vector<Interval>& intervals) {
		map<int, int> hm;
		for (auto &i: intervals) {
			++hm[i.start];
			--hm[i.end];
		}

		int cnt = 0, mx = 0;
		for (auto &kvp: hm) {
			cnt += kvp.second;
			mx = max(mx, cnt);
		}

		return mx;
    }
};
