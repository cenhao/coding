class RangeFreqQuery {
public:
	vector<pair<int, int>> a;
	unordered_map<int, pair<int, int>> rngs;
    RangeFreqQuery(vector<int>& arr) {
		int sz = arr.size();
		for (int i=0; i<sz; ++i) {
			a.emplace_back(arr[i], i);
		}

		sort(a.begin(), a.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
		});

		for (int i=0, last=-1; i<sz; ++i) {
			if (a[i].first != last) {
				rngs.insert(move(make_pair(a[i].first, make_pair(i, i))));
				last = a[i].first;
			} else {
				rngs[a[i].first].second = i;
			}
		}
    }
    
	int count(int st, int ed, int v) {
		int l = st, r = ed;
		while (l <= r) {
			int m = (l + r) / 2;
			if (a[m].second <= v) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return max(0, r-st+1);
	}
    int query(int left, int right, int value) {
		auto it = rngs.find(value);
		if (it == rngs.end()) { return 0; }
		auto rng = it->second;
		int cnt1 = count(rng.first, rng.second, left-1);
		int cnt2 = count(rng.first, rng.second, right);
		return cnt2 - cnt1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
