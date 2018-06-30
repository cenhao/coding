class Solution {
public:
    int judgeTheLastNumber(string &str) {
		int len = str.length(), last = 1;
		for (int i=0; i<len; ++i) {
			if (str[i] == '1') {
				++i;
				last = 2;
			} else {
				last = 1;
			}
		}

		return last;
    }
};
