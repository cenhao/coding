class FreqStack {
public:
	unordered_map<int, stack<int>> p;
	map<int, map<int, int, std::greater<int>>, std::greater<int>> freq;
	int pos;

    FreqStack() { pos = 0; }
    
    void push(int x) {
		int f = p[x].size();
		if (f != 0) { freq[f].erase(p[x].top()); }
		p[x].push(pos);
		freq[++f].emplace(pos++, x);
    }
    
    int pop() {
		auto it = freq.begin();
		int ret = it->second.begin()->second;

		it->second.erase(it->second.begin());
		if (it->second.size() == 0) { freq.erase(it); }

		p[ret].pop();
		if (p[ret].size() == 0) {
			p.erase(ret);
		} else {
			int f = p[ret].size();
			freq[f].emplace(p[ret].top(), ret);
		}

		return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
