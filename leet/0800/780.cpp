/*
 * Let's put this in a simpler set up, tx >= ty;
 * According to the rule, (x, y) -> (x, x+y) or (x+y, y)
 * The only way to get to (tx, ty) will be (tx'+n*ty, ty)
 * and hence then (tx', ty), (tx', ty')
 *
 * until either (or both) one reaches x or y, then figure out
 * if that's possible
 */
class Solution {
public:
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		if (tx < ty) { swap(tx, ty); swap(sx, sy); }
		while (tx > sx && ty > sy) {
			int tmp = ty;
			ty = tx % ty;
			tx = tmp;
			swap(sx, sy);
		}

		if (ty == sy) {
			if (tx >= sx && (tx-sx) % sy == 0) { return true; }
		}

		return false;
	}
};
