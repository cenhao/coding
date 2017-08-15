class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		sort(arr.begin(), arr.end(), [&](int a, int b) {
			int da = abs(a-x), db = abs(b-x);
			return da == db ? a < b : da < db;
		});

		vector<int> ans(k);
		for (int i=0; i<k; ++i) { ans[i] = arr[i]; }
		sort(ans.begin(), ans.end());
		return ans;
	}
};
