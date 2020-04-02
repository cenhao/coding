class DinnerPlates {
	set<int> nfs, nes;
	vector<stack<int>> stks;
	int cap;
public:
    DinnerPlates(int capacity) {
		cap = capacity;
    }
    
    void push(int val) {
		if (nfs.empty()) {
			stack<int> stk;
			stk.push(val);
			stks.emplace_back(move(stk));
			if (cap > 1) { nfs.insert(stks.size()-1); }
			nes.insert(stks.size()-1);
		} else {
			auto it = nfs.begin();
			int idx = *it;
			stks[idx].push(val);
			if (stks[idx].size() >= cap) { nfs.erase(it); }
			nes.insert(idx);
		}
    }
    
    int pop() {
		auto it = nes.rbegin();
		if (it == nes.rend()) { return -1; }
		int ret = stks[*it].top();
		stks[*it].pop();
		nfs.insert(*it);
		if (stks[*it].empty()) { nes.erase(*it); }
		return ret;
    }
    
    int popAtStack(int idx) {
		if (stks[idx].empty()) { return -1; }
		int ret = stks[idx].top();
		stks[idx].pop();
		nfs.insert(idx);
		if (stks[idx].empty()) { nes.erase(idx); }
		return ret;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
