class Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		for (auto &v: bookings) { --v[0]; --v[1]; }
		sort(bookings.begin(), bookings.end(), [](const vector<int> &v1, const vector<int> &v2) {
			return (v1[0] == v2[0]) ? v1[1] < v2[1] : v1[0] < v2[0];
		});
		auto cmp = [](const vector<int> &v1, const vector<int> &v2) {
			return v1[1] > v2[1];
		};
		priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
		vector<int> ans(n, 0);
		for (int i=0, j=0, acc=0; i<n; ++i) {
			while (!pq.empty() && pq.top()[1]<i) {
				acc -= pq.top()[2];
				pq.pop();
			}

			while (j<bookings.size() && bookings[j][0]<=i) {
				acc += bookings[j][2];
				pq.emplace(move(bookings[j]));
				++j;
			}

			ans[i] = acc;
		}

		return ans;
	}
};
