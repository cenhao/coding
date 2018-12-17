class Solution {
	void calc(int n1, int d1, int n2, int d2, char op, int &n, int &d) {
		if (op == 0) {
			n = d2 * n1 + d1 * n2; d = d1 * d2;
		} else if (op == 1) {
			n = d2 * n1 - d1 * n2; d = d1 * d2;
		} else if (op == 2) {
			n = n1 * n2; d = d1 * d2;
		} else {
			n = n1 * d2; d = n2 * d1;
		}
	}

	bool leftFirst(vector<int> &nums, vector<char> &op) {
		int n = nums[0], d = 1;
		for (int i=1; i<4; ++i) { calc(n, d, nums[i], 1, op[i-1], n, d); }
		return (d != 0 && (n%d) == 0 && n/d == 24);
	}

	bool rightFirst(vector<int> &nums, vector<char> &op) {
		int n = nums[3], d = 1;
		for (int i=2; i>=0; --i) { calc(nums[i], 1, n, d, op[i], n, d); }
		return (d != 0 && (n%d) == 0 && n/d == 24);
	}

	bool twoParts(vector<int> &nums, vector<char> &op) {
		int n1, n2, d1, d2;
		calc(nums[0], 1, nums[1], 1, op[0], n1, d1);
		calc(nums[2], 1, nums[3], 1, op[2], n2, d2);

		int n, d;
		calc(n1, d1, n2, d2, op[1], n, d);
		return (d != 0 && (n%d) == 0 && n/d == 24);
	}

	bool dfs1(vector<int> &nums, vector<char> &op, int cur) {
		if (cur == 3) { return leftFirst(nums, op) || rightFirst(nums, op) || twoParts(nums, op); }
		for (int i=0; i<4; ++i) {
			op[cur] = i;
			if (dfs1(nums, op, cur+1)) { return true; }
		}
		return false;
	}

	bool dfs(vector<int> &nums, int start) {
		if (start == 4) {
			vector<char> op(3);
			return dfs1(nums, op, 0);
		}

		for (int i=start; i<4; ++i) {
			swap(nums[i], nums[start]);
			if (dfs(nums, start+1)) { return true; }
			swap(nums[i], nums[start]);
		}

		return false;
	}
public:
	bool judgePoint24(vector<int>& nums) {
		return dfs(nums, 0);
	}
};
