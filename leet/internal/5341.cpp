class ProductOfNumbers {
	vector<int> pd;
	int latest_zero_idx;
public:
    ProductOfNumbers() {
		pd.push_back(1);
		latest_zero_idx = -1;
    }
    
    void add(int num) {
		if (num == 0) {
			latest_zero_idx = pd.size();
			pd.push_back(1);
		} else {
			int v = pd.back();
			pd.push_back(v * num);
		}
    }
    
    int getProduct(int k) {
		if (pd.size()-k <= latest_zero_idx) { return 0; }
		int v = pd.back();
		int idx = pd.size() - k - 1;
		return v / pd[idx];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
