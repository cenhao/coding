#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int findBlackPixel(vector<vector<char>>& picture, int N) {
		vector<int> hcnt(picture.size(), 0);
		vector<int> vcnt(picture[0].size(), 0);
		vector<int> hs(picture.size(), 0);
		
		for (int i=0; i<picture.size(); ++i) {
			for (int j=0; j<picture[i].size(); ++j) {
				if (picture[i][j] == 'B') {
					++hcnt[i]; ++vcnt[j];
				}
			}
		}

		for (int i=0; i<picture.size(); ++i) {
			if (hs[i] != 0 || hcnt[i] != N) { continue; }
			for (int j=0; j<picture[i].size(); ++j) {
				if (hcnt[i] == N && vcnt[j] == N && picture[i][j] == 'B') {
					int fc = 0;
					for (int k=0; k<picture.size(); ++k) {
						if (picture[k][j] == 'B') {
							if (hs[i] == 2) {
								++fc;
								continue;
							}
							if (hcnt[k] != N) {
								++fc;
								continue;
							}

							for (int l=0; l<picture[i].size(); ++l) {
								if (picture[i][l] != picture[k][l]) {
									++fc;
									break;
								}
							}
						}
					}

					hs[i] = fc > 0 ? 2 : 1;
					for (int k=0; k<picture.size(); ++k) {
						if (picture[k][j] == 'B') { hs[k] = hs[i]; }
					}
				}
			}
		}

		int ans = 0;
		for (int i=0; i<picture.size(); ++i) {
			if (hs[i] != 1 || hcnt[i] != N) { continue; }
			for (int j=0; j<picture[i].size(); ++j) {
				if (hcnt[i] == N && vcnt[j] == N && picture[i][j] == 'B') {
					printf("%d %d\n", i, j);
					++ans;
				}
			}
		}

		return ans;
	}
};

int main() {
	int n, m, N;
	cin >> n >> m;
	vector<vector<char>> pic(n, vector<char>(m));
	for (int i=0; i<n; ++i) {
		string s; cin >> s;
		for(int j=0; j<m; ++j) { pic[i][j] = s[j]; }
	}
	cin >> N;
	Solution sol;
	cout << sol.findBlackPixel(pic, N) << endl;
}
