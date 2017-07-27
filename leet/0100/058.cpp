class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0, cnt = 0;
		for (auto c : s) {
			if (!((c>='a' && c<='z') || (c>='A' && c<='Z'))) {
				if (cnt != 0) { len = cnt; }
				cnt = 0;
			} else {
				++cnt;
			}
		}

		if (cnt != 0) { len = cnt; }
		return len;
	}
};
