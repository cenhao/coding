class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		unordered_map<int, int> hm;
		for (auto b: barcodes) { ++hm[b]; }
		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.first < p2.first;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		for (auto &kvp: hm) {
			pq.emplace(make_pair(kvp.second, kvp.first));
		}
		pair<int, int> pre = make_pair(-1, -1);
		vector<int> ans(barcodes.size());
		int cnt = 0;
		while (!pq.empty()) {
			auto tmp = pq.top(); pq.pop();
			--tmp.first;
			ans[cnt++] = tmp.second;
			if (pre.first > 0) {
				pq.emplace(pre);
			}
			pre = tmp;
		}

		return ans;
	}
};
