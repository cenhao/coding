class MyCalendar {
public:
	class Cmp {
	public:
		bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
			return p2.second <= p1.first;
		}
	};
	set<pair<int, int>, Cmp> sche;
	MyCalendar() { }

	bool book(int start, int end) {
		auto p = make_pair(start, end);
		auto it = sche.lower_bound(p);
		if (it != sche.end()) {
			if (p.first < it->second) { return false; }
		}

		sche.insert(p);
		return true;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
