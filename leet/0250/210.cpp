class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<list<int>> out(numCourses);
		vector<int> in_cnt(numCourses, 0);
		for (auto &p : prerequisites) {
			++in_cnt[p.first];
			out[p.second].push_back(p.first);
		}

		queue<int> q;
		for (int i=0; i<numCourses; ++i) {
			if (in_cnt[i] == 0) { q.push(i); }
		}

		int used = 0;
		vector<int> ans(numCourses);
		while (!q.empty()) {
			int cur = ans[used++] = q.front();
			q.pop();
			for (auto o: out[cur]) {
				if (--in_cnt[o] == 0) { q.push(o); }
			}
		}

		if (used == numCourses) {
			return ans;
		}

		return vector<int>();
	}
};
