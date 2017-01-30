#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	long long try_base(long long n, long long base, int mpw /*max power*/) {
		long long sum = 0LL;
		for (int i=mpw; i>=0; --i) {
			long long tmp = 1LL, target = n-sum;
			for (int j=0; j<i; ++j) {
				if (tmp > target / base) { return n+1; }
				tmp *= base;
			}

			sum += tmp;
		}

		return sum;
	}

	string smallestGoodBase(string n) {
		long long num = atoll(n.c_str());
		long long mn = num - 1;

		long long mx = mn - 1;
		for (int i=2; i<64; ++i) {
			long long l = 2, r = mx, m, v;
			while (l <= r) {
				m = (l + r) >> 1;
				v = try_base(num, m, i);

				if (v > num) {
					r = m - 1;
				} else if (v < num) {
					l = m + 1;
				} else {
					break;
				}
			}

			if (v == num) {
				mn = m;
				mx = m - 1;
			} else {
				mx = r;
			}
		}

		char buf[20];
		snprintf(buf, 20, "%lld", mn);
		return string(buf);
	}
};

int main() {
	string in;
	while (cin >> in) {
		Solution sol;
		cout << sol.smallestGoodBase(in) << endl;
	}
	return 0;
}
