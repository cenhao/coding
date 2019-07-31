/*
 * |a_i - b_i| + |a_j - b_j| + |i - j| =
 * max {
 * 	1. ai+bi+i - aj+bj+j
 * 	2. ai-bi+i - aj-bj+j
 * 	3. -ai+bi+i - -aj+bj+j
 * 	4. -ai-bi+i - -aj-bj+j
 * } if consider i > j
 */
class Solution {
public:
	int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
		int sz = arr1.size();
		int64_t mn[4] = { 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff };
		int64_t mx = 0;
		for (int i=0; i<sz; ++i) {
			int64_t cur;

			cur = arr1[i] + arr2[i] + i;
			mx = max(mx, cur-mn[0]);
			mn[0] = min(mn[0], cur);

			cur = arr1[i] - arr2[i] + i;
			mx = max(mx, cur-mn[1]);
			mn[1] = min(mn[1], cur);

			cur = -arr1[i] + arr2[i] + i;
			mx = max(mx, cur-mn[2]);
			mn[2] = min(mn[2], cur);

			cur = -arr1[i] - arr2[i] + i;
			mx = max(mx, cur-mn[3]);
			mn[3] = min(mn[3], cur);
		}

		return mx;
	}
};
