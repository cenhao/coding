class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int sz = row.size();
		int hsz = sz / 2, cnt = 0;
		vector<int> pos(sz);
		for (int i=0; i<sz; ++i) {
			pos[row[i]] = i;
		}
		for (int i=0; i<hsz; ++i) {
			int need = row[i*2] ^ 1;
			if (row[i*2+1] != need) {
				++cnt;
				int tmp = pos[need];
				pos[row[i*2+1]] = pos[need];
				pos[need] = i*2+1;
				swap(row[i*2+1], row[tmp]);
			}
		}

		return cnt;
	}
};
