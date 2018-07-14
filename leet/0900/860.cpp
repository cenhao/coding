class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		unordered_map<int, int> cnt;
		bool ok = true;
		for (auto b: bills) {
			if (b == 5) {
				++cnt[5];
			} else if (b == 10) {
				if (cnt[5] == 0) {
					ok = false;
					break;
				}
				--cnt[5];
				++cnt[10];
			} else {
				if (cnt[10] > 0) {
					--cnt[10];
					b -= 10;
				}

				int need = (b-5) / 5;
				if (need > cnt[5]) {
					ok = false;
					break;
				}
				cnt[5] -= need;
			}
		}
		return ok;
	}
};
