class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> hm, st, ed;
		int mx = 0;
		for (int i=0; i<nums.size(); ++i) {
			int v = nums[i];
			mx = max(mx, ++hm[v]);
			if (st.find(v) == st.end()) { st[v] = i; }
			ed[v] = i;
		}
		int ans = 0x7fffffff;
		for (auto ent : hm) {
			if (ent.second == mx) {
				int v = ent.first;
				ans = min(ans, ed[v]-st[v]+1);
			}
		}
		return ans;
	}
};
