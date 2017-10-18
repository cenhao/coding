class Solution {
public:
	unordered_map<int, int> b2i;
	int lowbit(int x) { return x & (~(x-1)); }
	bool dfs(int target, int k, int cur, int ck, int checked, int avai, const vector<int> &nums) {
		if (k <= ck) { return avai == 0; }

		int tavai = avai & (~checked), last = -1;
		for (int lb=lowbit(tavai); tavai!=0; tavai-=lb, lb=lowbit(tavai)) {
			checked |= lb; // avoid checking again
			int idx = b2i[lb];
			if (nums[idx] == last) { continue; }
			last = nums[idx];
			if (cur + nums[idx] > target) { break; }
			if (cur + nums[idx] == target) {
				// an interesting branch cutting:
				// Once a combination of element sum to target,
				// we can take those off. if the array can be devided into
				// k group each sum to target, then without those elelemnts,
				// the array can be devided into k-1 group sum to target.
				// given two groups sum to target, if there're any element combinations
				// can be swapped, then swapping them won't change the sum
				return dfs(target, k, 0, ck+1, 0, avai & (~lb), nums);
			} else {
				if (dfs(target, k, cur+nums[idx], ck, checked, avai & (~lb), nums)) { return true; }
			}

			if (cur == 0) { break; }
		}

		return false;
	}

	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		for (auto n : nums) { sum += n; }
		if (sum % k != 0) { return false; }
		sort(nums.begin(), nums.end());
		int target = sum / k, sz = nums.size();
		for (int i=0; i<sz; ++i) { b2i[1<<i] = i; }
		return dfs(target, k, 0, 0, 0, (1<<sz)-1, nums);
	}
};
