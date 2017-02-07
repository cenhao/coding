#include <map>
#include <vector>
using namespace std;

class Solution {
	public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> ans(nums.size(), -1);
		multimap<int, int> vp; // value position

		for (int i=0, end=nums.size(); i<end; ++i) { nums.push_back(nums[i]); }

		for (int i=0, end=nums.size(); i<end; ++i) {
			auto it = vp.lower_bound(nums[i]);
			for (auto iit=vp.begin(); iit!=it; ++iit) {
				ans[iit->second] = nums[i];
			}

			vp.erase(vp.begin(), it);

			if (i < ans.size()) { vp.insert(pair<int, int>(nums[i], i)); }
		}

		return ans;
	}   
};
