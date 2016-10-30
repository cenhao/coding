#include <stack>
using namespace std;

#include <stdio.h>

int main() {
	int n; scanf("%d", &n);
	stack<int> s;
	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		if (!s.empty() && v < s.top()) {
			int mx = s.top();
			while (!s.empty() && v < s.top()) { s.pop(); }
			v = mx;
		}

		s.push(v);
	}

	printf("%d\n", s.size() == n ? 0 : int(n - s.size() + 1));
}
