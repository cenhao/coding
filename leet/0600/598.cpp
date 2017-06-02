class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int mxm = m, mxn = n;
		for (int i=0; i<ops.size(); ++i) {
			mxm = min(mxm, ops[i][0]);
			mxn = min(mxn, ops[i][1]);
		}

		return mxm * mxn;
	}
};
