class RangeModule {
public:
	struct Cmp {
		bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) const {
			return p1.second <= p2.first;
		}
	};
	set<pair<int, int>, Cmp> rc;

	RangeModule() { }

	void addRange(int left, int right) {
		auto rng = rc.equal_range(make_pair(left, right));
		int nleft = left;
		if (rng.first != rc.end()) { nleft = min(nleft, rng.first->first); }
		if (rng.first != rc.begin()) {
			auto pre = prev(rng.first);
			if (pre != rc.end() && pre->second == left) {
				nleft = pre->first;
				rng.first = pre;
			}
		}
		if (rng.second != rc.end() && rng.second->first == right) {
			right = rng.second->second;
			++rng.second;
		} else if (rng.second != rc.begin()) {
			auto pre = prev(rng.second);
			if (pre != rc.end()) {
				right = max(right, pre->second);
			}
		}

		rc.erase(rng.first, rng.second);
		rc.insert(make_pair(nleft, right));
	}

	bool queryRange(int left, int right) {
		auto it = rc.lower_bound(make_pair(left, right));
		return it!=rc.end() && it->first <= left && it->second >= right;
	}

	void removeRange(int left, int right) {
		auto rng = rc.equal_range(make_pair(left, right));
		int sv = right, ev = left;
		if (rng.first != rc.end()) {
			sv = rng.first->first;
			if (rng.second != rc.begin()) {
				auto pre = prev(rng.second);
				ev = max(ev, pre->second);
			}
		}
		rc.erase(rng.first, rng.second);
		if (sv < left) { rc.insert(make_pair(sv, left)); }
		if (right < ev) { rc.insert(make_pair(right, ev)); }
	}
};
