class Solution {
public:
	int minCostToMoveChips(vector<int>& chips) {
		int sz = chips.size();
		int mn = -1;
		for (int i=0; i<sz; ++i) {
			int sm = 0;
			for (int j=0; j<sz; ++j) {
				sm += abs(chips[i] - chips[j]) & 1;
			}

			if (mn==-1 || sm<mn) { mn = sm; }
		}

		return mn;
	}
};
