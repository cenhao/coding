class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int lena = A.length(), lenb = B.length();
		for (int i=lena; i<lenb; ++i) {
			if (B[i] != B[i-lena]) { return -1; }
		}

		for (int i=0; i<lena; ++i) {
			bool possible = true;
			for (int j=0, end=min(lena, lenb); j<end && possible; ++j) {
				if (B[j] != A[(i+j) % lena]) { possible = false; }
			}

			if (possible) {
				int take = min(lena, lenb);
				int exd = max(0, i+take-lena);
				take -= exd;
				lenb -= take;
				int need = 1;
				need += lenb / lena + (lenb % lena == 0 ? 0 : 1);
				return need;
			}
		}

		return -1;
	}
};
