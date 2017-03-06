class Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		vector<int> hcnt(picture.size(), 0);
		vector<int> vcnt(picture[0].size(), 0);
		for (int i=0; i<picture.size(); ++i) {
			for (int j=0; j<picture[i].size(); ++j) {
				if (picture[i][j] == 'B') {
					++hcnt[i];
					++vcnt[j];
				}
			}
		}

		int ans = 0;
		for (int i=0; i<picture.size(); ++i) {
			for (int j=0; j<picture[i].size(); ++j) {
				if (hcnt[i] == 1 && vcnt[j] == 1 && picture[i][j] == 'B') { ++ans; }
			}
		}

		return ans;
	}
};
