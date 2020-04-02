class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> target;
		for (int i=0; i<nums.size(); ++i) {
			int sz = target.size();
			auto it = (index[i] >= sz) ? target.end() : (target.begin()+index[i]);
			target.insert(it, nums[i]);
		}
		return target;
	}
};
