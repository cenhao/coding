class Solution {
public:
	string alphabetBoardPath(string target) {
		int x = 0, y = 0;
		string ans;
		for (auto c: target) {
			int idx = c - 'a';
			int tx = idx / 5, ty = idx % 5;
			if (tx == 5) {
				while (y > ty) { --y; ans += 'L'; }
				while (y < ty) { ++y; ans += 'R'; }
				while (x < tx) { ++x; ans += 'D'; } 
			} else {
				while (x < tx) { ++x; ans += 'D'; }
				while (x > tx) { --x; ans += 'U'; }
				while (y > ty) { --y; ans += 'L'; }
				while (y < ty) { ++y; ans += 'R'; }
			}
			ans += '!';
		}
		return ans;
	}
};
