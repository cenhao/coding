class Solution {
public:
	int kConcatenationMaxSum(vector<int>& arr, int k) {
		int sm = 0, mx = 0, cur = 0;
		for (auto a: arr) {
			sm += a;
			cur += a;
			if (cur > 0) {
				mx = max(cur, mx);
			} else {
				cur = 0;
			}
		}

		int ans = mx; // basic no repeat
		if (mx == sm) {
			int64_t v = mx;
			v = (v * k) % 1000000007;
			ans = max(int(v), mx);
		} else if (k >= 2) {
			int lmx = 0, lsm = 0, rsm = 0, rmx = 0;
			for (int i=0; i<arr.size(); ++i) {
				lsm += arr[i];
				lmx = max(lmx, lsm);
			}
			for (int i=arr.size()-1; i>=0; --i) {
				rsm += arr[i];
				rmx = max(rmx, rsm);
			}

			if (sm < 0) {
				ans = max(lmx + rmx, ans);
			} else {
				int64_t tmp = sm;
				tmp = (tmp * (k-2)) % 1000000007;
				ans = max(lmx + rmx + int(tmp), ans);
			}
		}

		return ans;
	}
};
