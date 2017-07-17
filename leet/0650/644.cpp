/*
 * first binary search the optimal value `tar`.
 * sum(i..j) / count(i..j) > tar
 * =>
 * sum(i..j) > tar * count(i..j)
 * =>
 * sum((nums[i]-tar)..(nums[j]-tar)) > 0
 *
 * Then the problem becomes: how to find range [i..j],
 * with count(i..j) >= k, and sum(d_i..d_j) > 0, in
 * O(n) time.
 *
 * To solve this, for each j from (k-1) to (n-1),
 * it's trivial to get the sum of range [j-k+1, j]. Next
 * step is to try to find the minimal i <= j-k+1, making
 * sum(d_i..dj) maximal. Use the `tail` to calculate this,
 * it is very similar to finding the consecutive subsequence
 * with maximal sum, that if the `tail` is less than 0,
 * no need to use anything further.
 */
class Solution {
public:
	bool test(const vector<int> &nums, int k, double tar) {
		int sz = nums.size();
		double sum = 0;
		for (int i=0; i<k; ++i) { sum += nums[i] - tar; }
		if (sum >= 0) { return true; }

		double tail = 0;
		for (int i=k; i<sz; ++i) {
			sum += nums[i] - nums[i-k]; // -tar + tar
			tail += nums[i-k] - tar;
			tail = max(tail, 0.0); // <- dp, finding max sum substring
			if (sum + tail >= 0) { return true; }
		}

		return false;
	}

	double findMaxAverage(vector<int>& nums, int k) {
		const double eps = 1e-6;
		int sz = nums.size();

		int psum = 0, asum = 0;
		for (auto v : nums) {
			asum += v;
			if (v >= 0) { psum += v; }
		}

		double mn = double(asum) / sz - eps;
		double mx = psum + eps;

		while (mn + eps < mx) {
			double mid = (mx + mn) / 2;
			if (test(nums, k, mid)) {
				mn = mid;
			} else {
				mx = mid;
			}
		}

		return mx;
	}
};
