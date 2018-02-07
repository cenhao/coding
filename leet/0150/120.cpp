class Solution {
public:
	int minimumTotal(vector<vector<int>>& t) {
		int d = t.size();
		for (int i=d-1; i>0; --i) {
			for (int j=0; j<i; ++j) {
				t[i-1][j] += min(t[i][j], t[i][j+1]);
			}
		}

		return t[0][0];
	}
};
