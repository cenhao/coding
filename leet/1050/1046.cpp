class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq;
		for (auto s: stones) { pq.push(s); }
		while (pq.size() > 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			int v = a - b;
			if (a > b) { pq.push(a-b); }
		}

		return pq.size() == 0 ? 0 : pq.top();
	}
};
