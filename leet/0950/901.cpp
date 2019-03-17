class StockSpanner {
	vector<int> v, c;
public:
    StockSpanner() {
    }
    
    int next(int price) {
		int cur = v.size() - 1;
		while (cur>=0 && price>=v[cur]) {
			cur -= c[cur];
		}
		int ret = v.size() - cur;
		v.push_back(price);
		c.push_back(ret);
		return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
