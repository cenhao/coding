class Solution {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int> arr = {a, b, c};
		sort(arr.begin(), arr.end());
		int mx = arr[1]-arr[0]-1 + arr[2]-arr[1]-1;
		int mn = min(1, arr[1]-arr[0]-1) + min(arr[2]-arr[1]-1, 1);
		if (arr[1]-2==arr[0] || arr[2]-2==arr[1]) { mn = min(mn, 1); }
		return vector<int> { mn, mx };
	}
};
