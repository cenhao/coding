class Solution {
public:
	int calc(vector<vector<int>>& a, vector<vector<int>>& b) {
		int rsz = a.size(), csz = a[0].size();
		int mx = 0;
		for (int i=-rsz+1; i<=rsz-1; ++i) {
			for (int j=-csz-1; j<=csz-1; ++j) {
				int cnt = 0;
				for (int x=0; x<rsz; ++x) {
					if (x+i<0 || x+i>=rsz) { continue; }
					for (int y=0; y<=csz; ++y) {
						if (y+j<0 || y+j>=csz) { continue; }
						if (a[x+i][y+j]==b[x][y] && b[x][y]==1) { ++cnt; }
					}   
				}   
				mx = max(mx, cnt);
			}   
		}   
		return mx; 
	}   
	int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
		if (a.empty() || a[0].empty()) { return 0; }
		int mx = calc(a, b); 
		mx = max(calc(b, a), mx);
		return mx; 
	}   
};
