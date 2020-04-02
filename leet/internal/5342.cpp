class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		sort(events.begin(), events.end(), [](const vector<int> &e1, const vector<int> &e2) {
			return e1[0] == e2[0] ? (e1[1] < e2[1]) : e1[0] < e2[0];
		});
		int mn = 0x7fffffff, mx = -1;
		for (auto &e: events) {
			mn = min(mn, e[0]);
			mx = max(mx, e[1]);
		}

		int cnt = 0, sz = events.size(), nxt = 0;
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i=mn; i<=mx; ++i) {
			while (nxt < sz && i>=events[nxt][0]) {
				pq.push(events[nxt][1]);
				++nxt;
			}
			while (!pq.empty() && pq.top()<i) { pq.pop(); }
			if (!pq.empty()) {
				pq.pop();
				++cnt;
			}
		}

		return cnt;
	}
};

