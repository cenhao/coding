class Solution {
public:
	int compress(vector<char>& chars) {
		int sz = chars.size(), pos = 0;
		char last = chars[0];
		for (int i=0, cnt=0; i<=sz; ++i) {
			if (i>=sz || chars[i] != last) {
				chars[pos++] = last;
				if (cnt > 1) {
					char buff[16];
					snprintf(buff, sizeof(buff), "%d", cnt);
					int len = strlen(buff);
					for (int j=0; j<len; ++j) {
						chars[pos++] = buff[j];
					}
				}
				cnt = 0;
				if (i < sz) { last = chars[i]; }
			}

			++cnt;
		}
		chars[pos] = 0;
		return pos;
	}
};
