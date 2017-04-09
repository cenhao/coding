class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> cnt;
		int mx = 0;
		for (int i=0; i<wall.size(); ++i) {
			int len = 0;
			for (int j=0; j<wall[i].size(); ++j) {
				len += wall[i][j];
				++cnt[len];
			}

			mx = max(mx, len);
		}

		int mn = 1000000;
		for (auto &ent : cnt) {
			if (ent.first != mx) {
				mn = min(int(wall.size())-ent.second, mn);
			}
		}

		return mn;
	}
};
