class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int T) {
		sort(clips.begin(), clips.end(), [](const vector<int> &c1, const vector<int> &c2) {
			return c1[0] != c2[0] ? c1[0] < c2[0] : c1[1] < c2[1];
		});
		vector<int> dp(T+1, -1);
		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.first != p2.first ? p1.first > p2.first : p1.second > p2.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		dp[0] = 0;
		for (int i=1, pos=0; i<=T; ++i) {
			while (pos<clips.size() && clips[pos][0] < i) {
				int idx = clips[pos][0];
				if (dp[idx] >= 0) { pq.emplace(make_pair(dp[idx]+1, clips[pos][1])); }
				++pos;
			}

			while (!pq.empty() && pq.top().second<i) { pq.pop(); }
			dp[i] = pq.empty() ? -1 : pq.top().first;
		}

		return dp[T];
	}
};
