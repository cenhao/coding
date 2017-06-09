#include <bits/stdc++.h>
using namespace std;

int visiblePoints(std::vector<std::vector<int>> points) {
	const double quar_pi = atan2(1, 1);
	const double pi = quar_pi * 4;
	const double two_pi = quar_pi * 8;
	const double eps = 1e-6;
	vector<double> angles(points.size());
	for (int i=0; i<points.size(); ++i) {
		angles[i] = atan2(points[i][1], points[i][0]);
	}

	sort(angles.begin(), angles.end());

	int mx = 0;
	for (int i=0, r=0, end=angles.size(); i<end; ++i) {
		do {
			double tmp = angles[r] + ((angles[r] < angles[i]) ? two_pi : 0);
			double diff = tmp - angles[i];
			if (diff > quar_pi + eps) { break; }
			r = (r + 1) % end;
		} while (r != i);

		int cnt = r - i + (r <= i ? end : 0);
		mx = max(cnt, mx);
	}

	return mx;
}

int main() {
	int n; cin >> n;
	vector<vector<int>> ps(n, vector<int>(2));
	for (int i=0; i<n; ++i) { cin >> ps[i][0] >> ps[i][1]; }
	cout << visiblePoints(ps);
	return 0;
}
