class Solution {
public:
	int countPrimeSetBits(int L, int R) {
		int cnt = 0;
		int ps[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
		unordered_set<int> pm;
		for (auto p : ps) { pm.insert(p); }

		for (int i=L; i<=R; ++i) {
			int n = i, scnt = 0;
			while (n != 0) {
				++scnt;
				int lb = n & (~(n-1));
				n -= lb;
			}

			if (pm.find(scnt) != pm.end()) { ++cnt; }
		}

		return cnt;
	}
};
