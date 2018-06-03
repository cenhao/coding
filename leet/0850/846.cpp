class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int w) {
		int sz = hand.size();
		if (sz % w != 0) { return false; }
		map<int, int> hm;
		for (auto h: hand) { ++hm[h]; }
		while (!hm.empty()) {
			int f = hm.begin()->first;
			for (int i=0; i<w; ++i) {
				if (hm.find(f+i) == hm.end()) { return false; }
				if (--hm[f+i] == 0) { hm.erase(f+i); }
			}
		}
		return true;
	}
};
