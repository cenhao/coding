class Solution {
public:
	int numRabbits(vector<int>& answers) {
		map<int, int> ccnt;
		for (auto a : answers) { ++ccnt[a]; }
		int ans = 0;
		for (auto &p : ccnt) {
			ans += (p.second+p.first) / (p.first+1) * (p.first+1);
		}

		return ans;
	}
};
