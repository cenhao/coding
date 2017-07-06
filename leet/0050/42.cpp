class Solution {
public:
    int trap(vector<int>& height) {
		int sz = height.size();
		vector<int> left(sz), right(sz);
		for (int i=0, mx=0; i<sz; ++i) {
			left[i] = mx;
			mx = max(mx, height[i]);
		}
		for (int i=sz-1, mx=0; i>=0; --i) {
			right[i] = mx;
			mx = max(mx, height[i]);
		}

		int ans = 0;
		for (int i=0; i<sz; ++i) {
			int w = max(min(left[i], right[i]), height[i]) - height[i];
			ans += w;
		}

		return ans;
    }
};
