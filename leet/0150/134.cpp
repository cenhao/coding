class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int len = gas.size();
		vector<bool> ok(len, false);

		int pg = -1;
		bool ok = false;
		for (int i=0, end=len*2,  pv=-1; i<end; ++i) {
			int ii = i % len;
			if (ii == pg && pv >= 0) {
				ok = true;
				break;
			}
			pv = ((pv >= 0) ? pv : 0) + gas[ii]-cost[ii];
			if (pv >= 0) {
				pg = (pg >= 0) ? pg : ii;
			} else {
				pg = -1;
			}
		}

		return ok ? pg : -1;
	}
};
