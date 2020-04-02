class Solution {
public:
	int test(int v) {
		int l = sqrt(v);
		for (int i=l; i>0; --i) {
			if ((v % i) == 0) { return i; }
		}
		return 1;
	}
	vector<int> closestDivisors(int num) {
		int one = test(num+1);
		int two = test(num+2);
		int d1 = abs(((num+1) / one) - one);
		int d2 = abs(((num+2) / two) - two);
		if (d1 < d2) {
			return { one, (num+1) / one };
		}
		return { two, (num+2) / two };
	}
};
