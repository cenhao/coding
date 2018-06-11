class NumMatrix {
	int lowbit(int x) { return x &(~(x-1)); }
	vector<vector<int>> bits2;
	vector<vector<int>> mat;
	void update(vector<int> &bits, int y, int v) {
		while (y < bits.size()) {
			bits[y] += v;
			y += lowbit(y);
		}
	}
	void update2(int x, int y, int v) {
		while (x < bits2.size()) {
			update(bits2[x], y, v);
			x += lowbit(x);
		}
	}
	int query(const vector<int> &bits, int y) {
		int res = 0;
		while (y > 0) {
			res += bits[y];
			y -= lowbit(y);
		}
		return res;
	}
	int query2(int x, int y) {
		int res = 0;
		while (x > 0) {
			res += query(bits2[x], y);
			x -= lowbit(x);
		}
		return res;
	}
public:
    NumMatrix(vector<vector<int>> matrix) {
		if (matrix.empty() || matrix[0].empty()) { return; }
		int rsz = matrix.size(), csz = matrix[0].size();
		mat = move(matrix);
		bits2.resize(rsz+1);
		for (int i=1; i<=rsz; ++i) { bits2[i].resize(csz+1, 0); }
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) { update2(i+1, j+1, mat[i][j]); }
		}
    }
    
    void update(int row, int col, int val) {
		if (mat.empty()) { return; }
		int delta = val - mat[row][col];
		mat[row][col] = val;
		update2(row+1, col+1, delta);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
		if (mat.empty()) { return 0; }
		int s22 = query2(row2+1, col2+1);
		int s12 = query2(row1, col2+1);
		int s21 = query2(row2+1, col1);
		int s11 = query2(row1, col1);
		return s22 - s12 - s21 + s11;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
