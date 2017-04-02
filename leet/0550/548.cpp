#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool splitArray(vector<int>& nums) {
		int sum = 0;
		for (int i=0; i<nums.size(); ++i) { sum += nums[i]; }
		vector<unordered_set<int>> vs(nums.size(), unordered_set<int>());
		int tsum = sum;
		for (int i=0; i+2<nums.size(); ++i) {
			if (i>0) { tsum -= nums[i-1]; }
			int lsum = nums[i];
			for (int j=i+1; j+1<nums.size(); ++j) {
				int rsum = tsum - lsum - nums[j];
				if (lsum == rsum) { vs[i].insert(lsum); }
				lsum += nums[j];
			}
		}

		int isum = 0;
		for (int i=1; i+5<nums.size(); ++i) {
			isum += nums[i-1];
			int jsum = 0;
			for (int j=i+2; j+3<nums.size(); ++j) {
				jsum += nums[j-1];
				if (isum == jsum && vs[j+i].end() != vs[j+1].find(isum)) {
					return true;
				}
			}
		}

		return false;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	Solution sol;
	cout << sol.splitArray(nums) << endl;
	return 0;
}
