class Solution {
public:
	bool canPermutePalindrome(string s) {
		int len = s.length();
		unordered_map<char, int> hm;
		for (auto c: s) { ++hm[c]; }
		int ocnt = 0;
		for (auto &kvp: hm) {
			ocnt += (kvp.second & 1);
		}
		return (ocnt == 0 || (ocnt==1 && (len&1)));
	}
};
