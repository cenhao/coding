class Solution {
public:
	int balancedString(string s) {
		unordered_map<char, int> hm;
		hm.emplace('Q', 0);
		hm.emplace('W', 1);
		hm.emplace('E', 2);
		hm.emplace('R', 3);
		int cnt[4] = { 0, 0, 0, 0 };
		for (auto c: s) { ++cnt[hm[c]]; }

		int len = s.length();
		int l = 0, r = len, req = len >> 2;;
		auto check = [&](int m) {
			int ncnt[4] = { 0, 0, 0, 0 };
			for (int i=0; i<len; ++i) {
				++ncnt[hm[s[i]]];
				if (i >= m) {
					--ncnt[hm[s[i-m]]];
				}

				if (cnt[0]-ncnt[0]<=req && cnt[1]-ncnt[1]<=req &&
					cnt[2]-ncnt[2]<=req && cnt[3]-ncnt[3]<=req) {
					return true;
				}
			}

			return false;
		};

		while (l <= r) {
			int m = (l + r) >> 1;
			if (check(m)) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		return l;
	}
};
