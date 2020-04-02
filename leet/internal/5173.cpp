class Solution {
public:
	bool isPrime(int v) {
		int cnt = 0;
		for (int i=1; i<=v && cnt<=2; ++i) {
			if (v % i == 0) { ++cnt; }
		}

		return cnt == 2;
	}
	int numPrimeArrangements(int n) {
		int pcnt = 0, npcnt = 0;
		for (int i=1; i<=n; ++i) {
			if (isPrime(i)) {
				++pcnt;
			} else {
				++npcnt;
			}
		}

		int64_t res = 1;
		for (int i=1; i<=pcnt; ++i) {
			res = (res * i) % 1000000007;
		}
		for (int i=1; i<=npcnt; ++i) {
			res = (res * i) % 1000000007;
		}
		return res;
	}
};
