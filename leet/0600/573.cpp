class Solution {
public:
	int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
		if (nuts.size() <= 0) { return 0; }
		int sum = 0;
		int mn = 0x7ffffff;
		for (int i=0; i<nuts.size(); ++i) {
			int dt = abs(tree[0]-nuts[i][0]) + abs(tree[1]-nuts[i][1]);
			int ds = abs(squirrel[0]-nuts[i][0]) + abs(squirrel[1]-nuts[i][1]);
			mn = min(mn, ds-dt);
			sum += dt * 2;
		}

		sum += mn;
		return sum;
	}
};
