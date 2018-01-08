/**
 * Definition for an interval.
 * struct Interval {
 * int start;
 * int end;
 * Interval() : start(0), end(0) {}
 * Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& a) {
		int sz = a.size();
		auto cmp = [](const Interval &i1, const Interval &i2) {
			return i1.end < i2.start;
		};

		set<Interval, decltype(cmp)> sm(cmp);
		for (auto &itvs : a) {
			for (auto &itv : itvs) {
				auto rng = sm.equal_range(itv);
				if (rng.first == sm.end() || rng.first->start > itv.end) {
					sm.insert(itv);
				} else {
					auto st = rng.first, ed = prev(rng.second);
					sm.erase(rng.first, rng.second);
					int sn = min(itv.start, st->start), en = max(itv.end, ed->end);
					Interval toin(sn, en);
					sm.insert(toin);
				}
			}
		}

		vector<Interval> ans;
		int pre = -1;
		for (auto &itv: sm) {
			if (pre >= 0) {
				Interval toin(pre, itv.start);
				ans.push_back(toin);
			}
			pre = itv.end;
		}

		return ans;
    }
};
