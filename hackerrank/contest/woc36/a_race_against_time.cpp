#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Student { int64_t h, p; } q[MAXN];

int64_t raceAgainstTime(int n, int mh, vector<int> h, vector<int> p) {
	map<int64_t, int> vcnt;
	vcnt[mh] = 1;
	q[0] = { mh, 0 };
	int qh = 0, qr = 1;

	for (int i=0; i<n-1; ++i) {
		int64_t tp = 0x7fffffffffffffff;
		while (qh!=qr && q[qr-1].h<h[i]) {
			tp = min(tp, h[i]-q[qr-1].h+q[qr-1].p+p[i]);
			auto it = vcnt.find(q[qr-1].p+q[qr-1].h);
			if (--it->second == 0) { vcnt.erase(it); }
			--qr;
		}
		if (vcnt.size() > 0) {
			tp = min(tp, vcnt.begin()->first+p[i]-h[i]);
		}
		q[qr++] = { h[i], tp };
		++vcnt[tp+h[i]];
	}

	int64_t ans = q[qh].p;
	for (int i=1; i<qr; ++i) { ans = min(ans, q[i].p); }
	return ans + n;
}

int main() {
    int n; cin >> n;
    int mason_height; cin >> mason_height;
    vector<int> heights(n-1);
    for(int heights_i = 0; heights_i < n-1; heights_i++){
       cin >> heights[heights_i];
    }
    vector<int> prices(n-1);
    for(int prices_i = 0; prices_i < n-1; prices_i++){
       cin >> prices[prices_i];
    }
    int64_t result = raceAgainstTime(n, mason_height, heights, prices);
    cout << result << endl;
    return 0;
}

