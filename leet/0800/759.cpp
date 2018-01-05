class Solution {
public:
	int intersectionSizeTwo(vector<vector<int>>& itvs) {
		sort(itvs.begin(), itvs.end(), [](const vector<int> &v1, const vector<int> &v2) {
			// ordering with r and l is necessary
			return (v1[1] == v2[1]) ? v1[0] > v2[0] : v1[1] < v2[1];
		});

		set<int> sm;
		for (auto &p : itvs) {
			auto it = sm.lower_bound(p[0]);
			if (it == sm.end()) {
				sm.insert(p[1]-1);
				sm.insert(p[1]);
			} else if (next(it) == sm.end()) {
				sm.insert(p[1]);
			}
		}

		return sm.size();
	}
};

// for data like
// 1 2
// 2 5
// 4 5
// if only ordered by `r`
// then for the first pair, set has [1, 2]
// second pair, [1, 2, 5]
// but for the third, it will try to insert 5 again
// but in fact it should insert 4 rather.
//
// If order by r then l
// we will insert [1, 2], then [4, 5], ending up
// with [1, 2, 4, 5], which is the final answer
