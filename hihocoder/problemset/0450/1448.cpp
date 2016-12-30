#include <cstdio>
#include <queue>
using namespace std;

struct Consecutive {
	int last, cnt;
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		bool possible = true;
		queue<Consecutive> q;
		for (int i=0; i<n; ++i) {
			int v; scanf("%d", &v);
			if (!possible || k == 1) { continue; }
			if (q.empty()) {
				Consecutive c = { v, 1 };
				q.push(c);
			} else if (v == q.front().last + 1) {
				q.front().last = v;
				++q.front().cnt;
				if (q.front().cnt != k) { q.push(q.front()); }
				q.pop();
			} else if (v == q.back().last) {
				Consecutive c = { v, 1 };
				q.push(c);
			} else {
				possible = false;
			}
		}

		printf(possible ? "YES\n" : "NO\n");
	}

	return 0;
}
