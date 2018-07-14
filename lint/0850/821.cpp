/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &a, vector<Interval> &b) {
		auto cmp = [](const Interval &i1, const Interval &i2) {
			return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;
		};
		sort(a.begin(), a.end(), cmp);
		sort(b.begin(), b.end(), cmp);
		vector<Interval> ans;
		auto ait = a.begin(), bit = b.begin();
		while (ait!=a.end() && bit!=b.end()) {
			int st = max(ait->start, bit->start), ed = min(ait->end, bit->end);
			if (st <= ed) { ans.emplace_back(st, ed); }
			if (ait->end <= bit->end) {
				++ait;
			} else {
				++bit;
			}
		}
		return ans;
    }
};
