class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int sz = arr.size(), cnt = 0;
		for (auto a: arr) {
			if (a == 0) { ++cnt; }
		}
		for (int i=sz-1, pos=sz+cnt-1; i>=0; --i) {
			if (pos < sz) { arr[pos] = arr[i]; }
			--pos;
			if (arr[i] == 0) {
				if (pos < sz) { arr[pos] = arr[i]; }
				--pos;
			}
		}
	}
};
