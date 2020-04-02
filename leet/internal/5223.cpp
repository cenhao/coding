class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		const int mov[8][2] = {
			{-1, 0}, {-1, -1}, {0, -1}, {1, -1},
			{1, 0}, {1, 1}, {0, 1}, {-1, 1}
		};

		unordered_map<int, int> hm;
		for (int i=0; i<queens.size(); ++i) {
			auto &q = queens[i];
			hm[q[0] * 8 + q[1]] = i;
		}

		vector<vector<int>> ans;
		for (int i=0; i<8; ++i) {
			vector<int> p = { -1, -1 };
			int mn = -1;
			for (int j=1; j<8; ++j) {
				int x = king[0]+j*mov[i][0], y = king[1]+j*mov[i][1];
				if (x<0 || x>7 || y<0 || y>7) { break; }
				auto it = hm.find(x*8 + y);
				if (it == hm.end()) { continue; }
				int idx = it->second;
				int dist = abs(queens[idx][0]-king[0]) + abs(queens[idx][1]-king[1]);
				if (p[0] == -1 || dist < mn) {
					mn = dist;
					p = queens[idx];
				}
			}
			if (mn >= 0) {
				ans.emplace_back(p);
			}
		}

		return ans;
	}
};
