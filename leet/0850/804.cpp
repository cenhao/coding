class Solution {
public:
	const vector<string> mm = {".-","-...","-.-.","-..",
		".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_set<string> hm;
		for (auto &w: words) {
			string tmp;
			for (auto c: w) { tmp += mm[c-'a']; }
			hm.insert(tmp);
		}

		return hm.size();
	}
};
