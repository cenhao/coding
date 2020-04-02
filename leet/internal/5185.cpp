class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		for (int i=0, cnt=0; i<arr.size(); ++i) {
			if (arr[i] % 2 == 1) {
				++cnt;
			} else {
				cnt = 0;
			}

			if (cnt >= 3) { return true; }
		}

		return false;
	}
};
