class Solution {
public:
	bool canCross(vector<int>& stones) {
		int sz = stones.size();
		unordered_map<int, int> hm;
		vector<vector<bool>> ok(sz, vector<bool>(sz, false));
		for (int i=0; i<sz; ++i) { hm[stones[i]] = i; }
		ok[0][0] = true;
		ok[0][1] = stones[1] == 1;
		bool ans = false;
		for (int i=0; i<sz; ++i) {
			if (ans |= ok[i][sz-1]) { break; }
			for (int j=i+1; j<sz; ++j) {
				if (!ok[i][j]) { continue; }
				int dist = stones[j] - stones[i];
				for (int k=-1; k<=1; ++k) {
					if (dist+k <= 0) { continue; }
					auto iter = hm.find(stones[j]+dist+k);
					if (iter != hm.end()) { ok[j][iter->second] = true; }
				}
			}
		}
		return ans;
	}
};
