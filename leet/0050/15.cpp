#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<vector<int> > threeSum(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int> > result;

			for (int i=0, end=nums.size()-2; i<end; ++i) {
				if (nums[i] > 0) { break; }
				if (i>0 && nums[i]==nums[i-1]) { continue; }
				for (int i1=i+1, end1=end+1; i1<end1; ++i1) {
					if (nums[i] + nums[i1] > 0) { break; }
					if (i1>i+1 && nums[i1]==nums[i1-1]) { continue; }
					int l = i1+1, r = end1, target = -(nums[i]+nums[i1]), m;
					while (l <= r) {
						m = (l + r) >> 1;
						if (nums[m] <= target) {
							l = m + 1;
						} else {
							r = m - 1;
						}
					}

					if (r > i1 && nums[r] == target) {
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[i1]);
						tmp.push_back(nums[r]);
						result.push_back(tmp);
					}
				}
			}

			return result;
		}
};

int main() {
	int n;
	while (cin >> n) {
		vector<int> in;
		for (int i=0; i<n; ++i) {
			int v; cin >> v;
			in.push_back(v);
		}
		Solution sol;
		vector<vector<int> > out = sol.threeSum(in);
		for (int i=0; i<out.size(); ++i) {
			cout << out[i][0] << " " << out[i][1] << " " << out[i][2] << endl;
		}
	}

	return 0;
}
