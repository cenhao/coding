class Solution {
public:
	int maxNumberOfBalloons(string text) {
		unordered_map<char, int> hm;
		for (auto c: text) { ++hm[c]; }
		int bcnt = hm['b'];
		int acnt = hm['a'];
		int lcnt = hm['l'] / 2;
		int ocnt = hm['o'] / 2;
		int ncnt = hm['n'];
		int ans = min(bcnt, min(acnt, min(lcnt, min(ocnt, ncnt))));
		return ans;
	}
};
