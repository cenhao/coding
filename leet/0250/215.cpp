class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq(nums.begin(), nums.end());
		--k;
		for (int i=0; i<k; ++i) { pq.pop(); }
		return pq.top();
	}
};
