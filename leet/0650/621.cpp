/*
 * 1. every time choose the task that has most remaining count.
 * 2. if follow #1, it can always be arranged to make the task flow leagal.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int cnt[26]; memset(cnt, 0, sizeof(cnt));
		int tsz = tasks.size();
		for (auto t : tasks) { ++cnt[t-'A']; }
		priority_queue<int> pq;
		for (int i=0; i<26; ++i) {
			if (cnt[i] > 0) { pq.push(cnt[i]); }
		}

		int buff[26], last;
		int ans = 0, done = 0;
		while (!pq.empty()) {
			last = 0;
			int space = n+1;
			while (!pq.empty() && space > 0) {
				if (pq.top() > 1) { buff[last++] = pq.top()-1; }
				pq.pop();
				++ans; --space;
			}

			for (int i=0; i<last; ++i) { pq.push(buff[i]); }
			if (!pq.empty()) { ans += space; }
		}

		return ans;
	}
};

int main() {
	string s; cin >> s;
	vector<char> v(s.begin(), s.end());
	int n; cin >> n;
	Solution sol;
	cout << sol.leastInterval(v, n) << endl;
	return 0;
}
