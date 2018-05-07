// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		int64_t l = 1, r = n;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (isBadVersion(m)) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return l;
    }
};
