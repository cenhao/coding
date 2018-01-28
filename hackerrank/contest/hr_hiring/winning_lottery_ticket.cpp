#include <bits/stdc++.h>

using namespace std;

int64_t winningLotteryTicket(vector <string> tickets) {
	int cnt[1<<10], full = (1<<10) - 1;
	memset(cnt, 0, sizeof(cnt));
	for (auto &t : tickets) {
		int bits = 0;
		for (auto c : t) { bits |= 1 << (c - '0'); }
		++cnt[bits];
	}

	int64_t ans = 0;
	for (int i=0; i<=full; ++i) {
		if (cnt[i] == 0) { continue; }
		for (int j=i+1; j<=full; ++j) {
			if (cnt[j] == 0 || (i|j) != full) { continue; }
			ans += (int64_t)cnt[i] * cnt[j];
		}
	}

	if (cnt[full] > 0) { ans += (int64_t)cnt[full] * (cnt[full]-1) >> 1; }
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<string> tickets(n);
	for(int tickets_i = 0; tickets_i < n; tickets_i++){
		cin >> tickets[tickets_i];
	}
	int64_t result = winningLotteryTicket(tickets);
	cout << result << endl;
	return 0;
}

