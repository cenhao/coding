class Solution {
public:
	vector<int> next_perm(const vector<int> &v, int sz) {
		vector<int> res(v);
		int pos;
		for (pos=sz-2; pos>=0; --pos) {
			if (res[pos] < res[pos+1]) { break; }
		}

		if (pos >= 0) {
			for (int i=sz-1; i>pos; --i) {
				if (res[i] > res[pos]) {
					swap(res[i], res[pos]);
					break;
				}
			}
		}

		for (int i=0, end=(sz-pos-1)/2; i<end; ++i) {
			swap(res[pos+1+i], res[sz-1-i]);
		}

		return res;
	}
	vector<vector<int>> permute(vector<int>& nums) {
		int sz = nums.size();
		vector<vector<int>> ans;
		if (sz <= 0) { return ans; }
		sort(nums.begin(), nums.end());
		while (true) {
			ans.push_back(nums);
			nums = move(next_perm(nums, sz));
			bool ordered = true;
			int last = nums[0];
			for (int i=1; i<sz; ++i) {
				if (nums[i] < last) {
					ordered = false;
					break;
				}

				last = nums[i];
			}

			if (ordered) { break; }
		}

		return ans;
	}
};
