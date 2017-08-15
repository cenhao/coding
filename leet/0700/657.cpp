class Solution {
public:
	bool judgeCircle(string moves) {
		int x = 0, y = 0;
		for (int i=0; i<moves.length(); ++i) {
			char m = moves[i];
			if (m == 'U') {
				--x;
			} else if (m == 'D') {
				++x;
			} else if (m == 'R') {
				++y;
			} else {
				--y;
			}
		}

		return x == 0 && y == 0;
	}
};
