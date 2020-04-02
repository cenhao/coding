class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {
		int sm = 0;
		for (auto n: nums) {
			int ed = sqrt(n);
			int cnt = 2, tmp = 1 + n;
			for (int i=2; i<=ed; ++i) {
				if (n % i == 0) {
					cnt += 1;
					tmp += i;
					if (n/i != i) {
						cnt += 1;
						tmp += n/i;
					}
				}
			}

			if (cnt == 4) { sm += tmp; }
		}

		return sm;
	}
};
