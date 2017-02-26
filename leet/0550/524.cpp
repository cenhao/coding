class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		sort(d.begin(), d.end(), [](const string &s1, const string &s2) -> bool {
			if (s1.length() == s2.length()) {
				return s1 < s2;
			}

			return s1.length() > s2.length();
		});

		vector<int> ml(d.size(), 0);
		for (int i=0; i<s.length(); ++i) {
			for (int j=0; j<d.size(); ++j) {
				if (ml[j] >= d[j].length()) { continue; }
				if (s[i] == d[j][ml[j]]) { ++ml[j]; }
			}
		}

		for (int i=0; i<d.size(); ++i) {
			if (ml[i] == d[i].length()) { return d[i]; }
		}

		return "";
	}
};
