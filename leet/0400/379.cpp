class PhoneDirectory {
private:
	map<int, int> avai;
	int mn, mx;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
		mn = 0, mx = maxNumbers - 1;
		avai.insert(make_pair(maxNumbers-1, maxNumbers));
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
		if (avai.empty()) { return -1; }
		auto it = avai.begin();
		int ret = it->first - it->second + 1;
		if (--it->second == 0) { avai.erase(it); }
		return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
		auto it = avai.lower_bound(number);
		return !(it==avai.end() || it->first-it->second+1>number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
		if (number<mn || number>mx) { return; }
		auto it = avai.lower_bound(number);
		if (it == avai.end()) {
			if (avai.empty() || (--it)->first+1<number) {
				avai.insert(make_pair(number, 1));
			} else {
				int cnt = it->second + 1;
				avai.erase(it);
				avai.insert(make_pair(number, cnt));
			}
		} else {
			if (it->first-it->second>number) {
				it = avai.insert(make_pair(number, 1)).first;
			} else {
				if (it->first-it->second+1 <= number) { return; }
				++it->second;
			}
			int pv = it->first-it->second;
			if (it!=avai.begin() && prev(it)->first==pv) {
				it->second += prev(it)->second;
				avai.erase(prev(it));
			}
		}
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
