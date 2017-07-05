class Solution {
public:
	string countAndSay(int n) {
		string cur = "1", tmp;
		for (int i=2; i<=n; ++i) {
			char last = cur[0], buff[8];
			int cnt = 1;
			for (int j=1, len=cur.length(); j<=len; ++j) {
				if (j == len || cur[j] != last) {
					snprintf(buff, sizeof(buff), "%d", cnt);
					tmp += buff;
					tmp += last;
					cnt = 0;
					if (j != len) { last = cur[j]; }
				}

				++cnt;
			}

			cur = move(tmp);
			tmp = "";
		}

		return cur;
	}
};
