class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		bool inc = true;
		for (int i=1; i<A.size(); ++i) {
			if (A[i] < A[i-1]) {
				inc = false;
				break;
			}
		}
		if (inc) { return true; }
		bool dec = true;
		for (int i=1; i<A.size(); ++i) {
			if (A[i] > A[i-1]) {
				dec = false;
				break;
			}
		}
		return dec;
	}
};
