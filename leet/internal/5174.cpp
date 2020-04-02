class Solution {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int p = 0, sm = 0;
		for (int i=0; i<calories.size(); ++i) {
			sm += calories[i];
			if (i >= k) { sm -= calories[i-k]; }
			if (i >= k-1) {
				if (sm > upper) { ++p; }
				if (sm < lower) { --p; }
			}
		}

		return p;
	}
};
