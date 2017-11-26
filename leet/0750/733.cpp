class Solution {
public:
	struct Pos { int x, y; };
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int color = image[sr][sc];
		if (color == newColor) { return image; }
		int sz = image.size(), ssz = image[0].size();
		const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		queue<Pos> q;
		Pos tmp = { sr, sc };
		image[sr][sc] = newColor;
		q.push(tmp);
		while (!q.empty()) {
			tmp = q.front(); q.pop();
			Pos tmp1;
			for (int i=0; i<4; ++i) {
				tmp1.x = tmp.x + mov[i][0]; tmp1.y = tmp.y + mov[i][1];
				if (tmp1.x<0 || tmp1.x>=sz || tmp1.y<0 || tmp1.y>=ssz || image[tmp1.x][tmp1.y] != color) {
					continue;
				}

				image[tmp1.x][tmp1.y] = newColor;
				q.push(tmp1);
			}
		}

		return image;
	}
};
