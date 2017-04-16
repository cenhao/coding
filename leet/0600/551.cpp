class Solution {
public:
	bool checkRecord(string s) {
		int acnt = 0;
		int lcnt = 0;
		bool fail = false;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == 'L') {
				++lcnt;
				if (lcnt > 2) { fail = true; }
			}
			else if (s[i] == 'A') {
				++acnt;
				lcnt = 0;
				if (acnt > 1) { fail = true; }
			}
			else {
				lcnt = 0;
			}
		}

		return !fail;
	}
};
