class Solution {
public:
	bool checkPerfectNumber(int num) {
		int end = sqrt(num);
		int sum = 0;
		for (int i=1; i<=end; ++i) {
			if (num % i == 0) {
				sum += i;
				if (num / i != i) { sum += num/i; }
			}
		}

		sum -= num;
		return sum == num;
	}
};
