#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
	public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> ans(findNums.size());
		for (int i=0; i<findNums.size(); ++i) {
			ans[i] = -1;
			bool find = false;
			for (int j=0; j<nums.size(); ++j) {
				if (find) {
					if (nums[j] > findNums[i]) {
						ans[i] = nums[j];
						break;
					}
				} else {
					find = nums[j] == findNums[i];
				}
			}
		}

		return ans;
	}
};
