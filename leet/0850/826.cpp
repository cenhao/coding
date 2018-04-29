class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		int sz = difficulty.size();
		vector<int> idx(sz);
		for (int i=0; i<sz; ++i) { idx[i] = i; }
		sort(idx.begin(), idx.end(), [&difficulty] (int a, int b) {
			return difficulty[a] < difficulty[b];
		});
		sort(worker.begin(), worker.end());
		int mx = 0, pos = 0, ans = 0;
		for (int i=0; i<worker.size(); ++i) {
			while (pos<sz && difficulty[idx[pos]]<=worker[i]) {
				mx = max(profit[idx[pos++]], mx);
			}
			ans += mx;
		}
		return ans;
	}
};
