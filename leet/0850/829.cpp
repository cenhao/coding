class Solution {
public:
	int consecutiveNumbersSum(int n) {
		int ans = 0, t_n = n<<1;
		for (int i=1; (i*i+i-t_n)<=0; ++i) {
			if ((t_n % i) != 0) { continue; }
			if (((t_n/i-i-1) & 1) == 0) { ++ans; }
		}
		return ans;
	}
};
