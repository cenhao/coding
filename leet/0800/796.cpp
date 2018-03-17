class Solution {
public:
	bool rotateString(string a, string b) {
		int alen = a.length(), blen = b.length();
		if (alen != blen) { return false; }
		a += a;
		bool found = false;
		for (int i=0; i<alen && !found; ++i) {
			bool ok = true;
			for (int j=0; j<blen && ok; ++j) {
				if (a[i+j] != b[j]) { ok = false; }
			}

			if (ok) { found = true; }
		}

		return found;
	}
};
