class MyCalendarThree {
	map<int, int> cnt;
	int mx;
public:
    MyCalendarThree() { mx = 0; }
    
    int book(int start, int end) {
		++cnt[start]; --cnt[end];
		int cmx = 0, v = 0;
		for (auto &kvp: cnt) {
			v += kvp.second;
			cmx = max(v, cmx);
		}

		return mx = max(mx, cmx);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
