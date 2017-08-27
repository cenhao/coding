class Solution {
public:
	int pathSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> sum(5, vector<int>(8, 0));
		vector<vector<bool>> ext(5, vector<bool>(8, false));
		int ans = 0;
		for (auto n : nums) {
			int i = n / 100, j = (n / 10) % 10, v = n % 10;
			sum[i][j] = v + sum[i-1][(j+1)/2];;
			ext[i][j] = true;
			ans += sum[i][j];
			if (ext[i-1][(j+1)/2]) {
				ext[i-1][(j+1)/2] = false;
				ans -= sum[i-1][(j+1)/2];
			}
		}

		return ans;
	}
};
