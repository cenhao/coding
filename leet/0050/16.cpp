#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			
			int dist = -1;
			int result;
			for (int i=0, end=nums.size()-2; i<end; ++i) {
				for (int i1=i+1, end1=end+1; i1<end1; ++i1) {
					int need = target - nums[i1] - nums[i];
					int l=i1+1, r=end1, m;
					while (l <= r) {
						m = (l + r) >> 1;
						if (nums[m] <= need) {
							l = m + 1;
						} else {
							r = m - 1;
						}
					}

					int v1 = nums[i1] + nums[i] + ((l <= end1) ? nums[l] : nums[r]);
					int v2 = nums[i1] + nums[i] + ((r > i1) ? nums[r] : nums[l]);
					int d1 = abs(v1 - target);
					int d2 = abs(v2 - target);
					v1 = d1 < d2 ? v1 : v2;
					d1 = d1 < d2 ? d1 : d2;
					if (dist < 0 || d1 < dist) {
						dist = d1;
						result = v1;
					}
				}
			}

			return result;
		}
};

int main() {
	int n, t;
	while (cin >> n) {
		vector<int> in;
		for (int i=0; i<n; ++i) { int v; cin >> v; in.push_back(v); }
		cin >> t;
		Solution sol;
		cout << sol.threeSumClosest(in, t) << endl;
	}

	return 0;
}
