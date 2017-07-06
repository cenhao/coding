class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int sz = matrix.size();
		for (int i=0, end=sz/2; i<end; ++i) {
			for (int j=i, jend=sz-i-1, len=sz-2*i; j<jend; ++j) {
				int nx = j, ny = len-1+i;
				swap(matrix[i][j], matrix[nx][ny]);
				int nnx = ny, nny = len-1-nx+2*i;
				swap(matrix[i][j], matrix[nnx][nny]);
				nx = nny; ny = len-1-nnx+2*i;
				swap(matrix[i][j], matrix[nx][ny]);
			}
		}
	}
};
