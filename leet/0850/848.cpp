class Solution {
public:
	string shiftingLetters(string s, vector<int>& shifts) {
		int64_t sm = 0;
		for (auto s: shifts) { sm += s; }
		for (int i=0; i<s.length(); ++i) {
			if (i >= shifts.size()) { break; }
			s[i] = ((s[i]-'a'+sm) % 26) + 'a';
			sm -= shifts[i];
		}

		return s;
	}
};
