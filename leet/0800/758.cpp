class Solution {
public:
	string boldWords(vector<string>& words, string s) {
		int len = s.length(), sz = words.size();
		vector<bool> b(len, false);
		for (int i=0; i<sz; ++i) {
			int wlen = words[i].length();
			for (int j=0; j<len; ++j) {
				bool ok = true;
				for (int k=0; k<wlen; ++k) {
					if (s[j+k] != words[i][k]) {
						ok = false;
						break;
					}
				}

				if (!ok) { continue; }
				for (int k=0; k<wlen; ++k) { b[j+k] = true; }
			}
		}

		string ans;
		bool in = false;
		for (int i=0; i<len; ++i) {
			if (b[i] && !in) {
				ans += "<b>";
				in = true;
			} else if (!b[i] && in) {
				ans += "</b>";
				in = false;
			}

			ans += s[i];
		}

		if (in) { ans += "</b>"; }

		return ans;
	}
};
