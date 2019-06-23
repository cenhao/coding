/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int t, MountainArray &ma) {
		int len = ma.length();
		int l = 0, r = len - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (m == len-1) {
				r = m - 1;
			} else {
				int v = ma.get(m), vv = ma.get(m+1);
				if (v > vv) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			}
		}

		int peaki = l;
		l = 0, r = peaki;
		while (l <= r) {
			int m = (l + r) / 2;
			int v = ma.get(m);
			if (v > t) {
				r = m - 1;
			} else if (v < t) {
				l = m + 1;
			} else {
				return m;
			}
		}

		l = peaki, r = len - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			int v = ma.get(m);
			if (v > t) {
				l = m + 1;
			} else if (v < t) {
				r = m - 1;
			} else {
				return m;
			}
		}

		return -1;
    }
};
