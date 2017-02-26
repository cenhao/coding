#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		if (k == 0) {
			int cnt = 0;
			for (int i=0; i<nums.size(); ++i) {
				if (nums[i] == 0) { ++cnt; }
				else { cnt = 0; }

				if (cnt > 1) { return true; }
			}

			return false;
		}
		unordered_map<int, int> hashmap;
		int sum = 0;
		for (int i=0; i<nums.size(); ++i) {
			sum += nums[i];
			sum %= k;
			++hashmap[sum];
		}

		sum = 0;
		for (int i=0; i<nums.size()-1; ++i) {
			int tmp = sum;
			sum += nums[i];
			sum %= k;
			if (hashmap[sum] > 0) {
				int v = --hashmap[sum];
				if (v == 0) { hashmap.erase(sum); }
			}
			if (hashmap[tmp] != 0) { return true; }
		}

		return false;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	int k; cin >> k;
	Solution sol;
	cout << sol.checkSubarraySum(nums, k) << endl;
	return 0;
}
