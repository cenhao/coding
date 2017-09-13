class Solution {
public:
	struct SItem { int h, pos; };
	int maximalRectangle(vector<vector<char>>& matrix) {
		int h = matrix.size();
		if (h == 0) { return 0; }
		int w = matrix[0].size();
		if (w == 0) { return 0; }

		vector<int> hi(w, 0);
		stack<SItem> s;
		int mx = 0;

		for (int i=0; i<h; ++i) {
			for (int j=0; j<=w; ++j) {
				if (j < w) { hi[j] = (matrix[i][j] == '1') ? hi[j]+1 : 0; }

				int last = j;
				while (!s.empty() && (j==w || hi[j]<s.top().h)) {
					SItem tmp = s.top(); s.pop();
					mx = max(mx, tmp.h * (j-tmp.pos));
					last = tmp.pos;
				}

				if (j < w) {
					SItem tmp = { hi[j], last };
					s.push(tmp);
				}
			}
		}

		return mx;
	}
};
