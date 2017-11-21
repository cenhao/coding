class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ans;
		for (int i=left; i<=right; ++i) {
			string str = to_string(i);
			bool ok = true;
			int cur = i;
			while (cur != 0) {
				int r = cur % 10;
				if (r == 0 || i % r != 0) {
					ok = false;
					break;
				}

				cur /= 10;
			}

			if (ok) { ans.push_back(i); }
		}

		return ans;
	}
};
