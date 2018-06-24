class Solution {
public:
	double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
		vector<pair<int, int>> lst(q.size());
		for (int i=0; i<q.size(); ++i) { lst[i] = make_pair(w[i], q[i]); }
		sort(lst.begin(), lst.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.first * p2.second < p1.second * p2.first;
		});

		priority_queue<int> pq;
		double mn = -1;
		int qsm = 0;
		for (int i=0; i<q.size(); ++i) {
			if (i < k) {
				pq.push(lst[i].second);
				qsm += lst[i].second;

				if (i == k-1) { mn = double(lst[i].first) * qsm / lst[i].second; }
			} else {
				int tmp = qsm - pq.top() + lst[i].second;
				mn = min(mn, double(lst[i].first) * tmp / lst[i].second);
				if (lst[i].second < pq.top()) {
					qsm = qsm - pq.top() + lst[i].second;
					pq.pop();
					pq.push(lst[i].second);
				}
			}
		}

		return mn;
	}
};
