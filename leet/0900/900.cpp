class RLEIterator {
private:
	int idx, used;
	vector<int> a;
public:
    RLEIterator(vector<int> A) {
		used = idx = 0;
		a = A;
    }
    
    int next(int n) {
		while (idx<a.size() && n>a[idx]-used) {
			n -= a[idx]-used;
			idx += 2;
			used = 0;
		}

		if (idx >= a.size()) { return -1; }
		used += n;
		return a[idx+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
