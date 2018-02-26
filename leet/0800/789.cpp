class Solution {
public:
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		int dist = abs(target[0]) + abs(target[1]);
		bool ok = true;
		for (int i=0; i<ghosts.size() && ok; ++i) {
			int td = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
			if (td <= dist) { ok = false; }
		}

		return ok;
	}
};
