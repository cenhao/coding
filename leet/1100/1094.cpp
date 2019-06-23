class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return (p1.first==p2.first) ? p1.second>p2.second : p1.first>p2.first;
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		for (auto &t: trips) {
			pq.emplace(make_pair(t[1], t[0]));
			pq.emplace(make_pair(t[2], -t[0]));
		}

		int cur = 0;
		while (!pq.empty() && cur<=capacity) {
			auto tmp = pq.top(); pq.pop();
			cur += tmp.second;
		}

		return pq.empty() && cur<=capacity;
	}
};
