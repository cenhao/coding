class Solution {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		int llen = licensePlate.length();
		int cnt = 0;
		vector<int> cm(26, 0);
		for (int i=0; i<llen; ++i) {
			char c = tolower(licensePlate[i]);
			if (c >= 'a' && c <= 'z') {
				++cnt;
				++cm[c-'a'];
			}
		}

		int wsz = words.size();
		int mn = -1, pos;
		for (int i=0; i<wsz; ++i) {
			int len = words[i].length();
			vector<int> scm(26, 0);
			int mcnt = 0;
			for (int j=0; j<len && mcnt<cnt; ++j) {
				char c = tolower(words[i][j]);
				if (c > 'z' || c < 'a') { continue; }
				c -= 'a';
				++scm[c];
				if (scm[c] <= cm[c]) { ++mcnt;  }
			}

			if (mcnt >= cnt) {
				if (mn == -1 || len < mn) {
					mn = len;
					pos = i;
				}
			}
		}

		return words[pos];
	}
};
