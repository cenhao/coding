class MyCalendarTwo {
public:
	vector<pair<int, int>> itvl;
    MyCalendarTwo() { }
    
    bool book(int start, int end) {
		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.second <= p2.first;
		};
		pair<int, int> np = make_pair(start, end);
		set<pair<int, int>, decltype(cmp)> overlap(cmp);
		for (auto &p : itvl) {
			int st = max(start, p.first);
			int ed = min(end, p.second);
			if (st >= ed) { continue; }
			auto it = overlap.lower_bound(p);
			if (it != overlap.end() && it->first < p.second) { return false; }
			overlap.insert(p);
		}

		itvl.push_back(np);
		return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
