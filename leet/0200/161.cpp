class Solution {
public:
	bool check(string &s, string &t, int sp, int tp, bool edited) {
		if (sp > s.length() || tp > t.length()) { return false; }
		if (sp == s.length()) {
			return tp == t.length()+(edited?0:-1);
		} else if (tp == t.length()) {
			return edited ? false : sp==s.length()-1;
		}

		if (s[sp] == t[tp]) {
			return check(s, t, sp+1, tp+1, edited);
		} else {
			if (!edited) {
				if (check(s, t, sp+1, tp+1, true)) {
					return true;
				} else if (check(s, t, sp, tp+1, true)) {
					return true;
				} else if (check(s, t, sp+1, tp, true)) {
					return true;
				}
			}
		}

		return false;
	}
	bool isOneEditDistance(string s, string t) {
		return check(s, t, 0, 0, false);
	}
};
