class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (auto &r: A) { reverse(r.begin(), r.end()); }
		for (auto &r: A) {
			for (auto &e: r) { e ^= 1; }
		}

		return A;
	}
};
