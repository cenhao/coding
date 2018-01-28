class Solution {
public:
	int numJewelsInStones(string J, string S) {
		bool isj[128];
		memset(isj, false, sizeof(isj));
		for (auto c : J) { isj[c] = true; }
		int cnt = 0;
		for (auto c : S) {
			if (isj[c]) { ++cnt; }
		}

		return cnt;
	}
};
