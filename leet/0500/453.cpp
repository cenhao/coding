#include <algorithm>
#include <vector>
using namespace std;

class Solution {
	public:
		int minMoves(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			int sum = 0;
			for (int i=nums.size()-1; i>=1; --i) {
				sum += nums[i] - nums[0];
			}

			return sum;
		}
};
