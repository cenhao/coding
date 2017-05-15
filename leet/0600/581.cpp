class Solution {
public:
	struct SItem { int v, idx; };
	int findUnsortedSubarray(vector<int>& nums) {
		int start = nums.size(), end = 0;
		bool mxs = false;
		int mx = 0;
		stack<SItem> st;
		for (int i=0; i<nums.size(); ++i) {
			while (!st.empty() && nums[i] < st.top().v) {
				SItem si = st.top(); st.pop();
				start = min(start, si.idx);
			}

			if (mxs && nums[i] < mx) { end = i; }
			st.push({nums[i], i});
			if (!mxs || nums[i] > mx) {
				mx = nums[i];
				mxs = true;
			}
		}

		return max(0, end - start + 1);
	}
};
