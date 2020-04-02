class Solution {
public:
	int maximumSum(vector<int>& arr) {
		int sz = arr.size();
		vector<int> dpf(sz), dpb(sz); // forward, backward

		for (int i=0, sm=0; i<sz; ++i) {
			dpf[i] = sm += arr[i];
			if (sm < 0) { sm = 0; }
		}
		for (int i=sz-1, sm=0; i>=0; --i) {
			dpb[i] = sm += arr[i];
			if (sm < 0) { sm = 0; }
		}

		int mx;
		bool set = false;
		for (int i=0; i<sz; ++i) {
			int v = dpf[i];
			if (i+1 < sz) {
				v = max(v, dpf[i]+arr[i+1]);
				v = max(v, dpf[i]+dpb[i+1]);
				if (i+2 < sz) {
					v = max(v, dpf[i]+dpb[i+2]);
				}
			}

			if (!set || v>mx) {
				mx = v;
				set = true;
			}
		}

		return mx;
	}
};
