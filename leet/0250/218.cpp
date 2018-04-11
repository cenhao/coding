class Solution {
public:
	struct VEdge {
		int id, pos, h;
		bool start;
	};
	vector<pair<int, int>> getSkyline(vector<vector<int>>& b) {
		int sz = b.size();
		vector<pair<int, int>> ans;
		if (sz == 0) { return ans; }
		vector<VEdge> edges(sz*2);
		for (int i=0; i<sz; ++i) {
			edges[i*2] = { i, b[i][0], b[i][2], true };
			edges[i*2+1] = { i, b[i][1], b[i][2], false };
		}
		sort(edges.begin(), edges.end(), [](const VEdge &e1, const VEdge &e2) {
			return e1.pos < e2.pos;
		});
		auto cmp = [](const VEdge &e1, const VEdge &e2) { return e1.h < e2.h; };
		priority_queue<VEdge, vector<VEdge>, decltype(cmp)> pq(cmp);
		vector<bool> act(sz, false);

		int pos = edges[0].pos, mxh = -1;
		for (int i=0, end=sz<<1; i<=end; ++i) {
			if (i==end || edges[i].pos!=pos) {
				while (!pq.empty() && !act[pq.top().id]) { pq.pop(); }
				if (pq.empty() || pq.top().h != mxh) {
					mxh = pq.empty() ? 0 : pq.top().h;
					ans.push_back(make_pair(pos, mxh));
				}
				if (i == end) { break; }
			}
			if (edges[i].start) {
				act[edges[i].id] = true;
				pq.push(edges[i]);
			} else {
				act[edges[i].id] = false;
			}
			pos = edges[i].pos;
		}

		return ans;
	}
};

