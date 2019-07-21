#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class WeirdTriangle {
public:
	long long findAllTriangle(int n, vector <int> b, int seed, int mod) {
		if (n < 3) { return 0LL; }

		vector<long long> a(n);
		a[0] = seed;
		long long cnt = 0;
		for (int i=1; i<n; ++i) { a[i] = (a[i-1]*1103515245LL + 12345) % 2147483648LL; }
		for (int i=0; i<n; ++i) {
			long long v = (i < b.size()) ? (long long)(b[i]) : (2*(a[i]%mod)-mod+1);
			if (v > 0) { ++cnt; }
		}

		if (cnt < 3) { return 0; }
		long long ans = cnt*(cnt-1)*(cnt-2) / 6;
		return ans;
	}
};

int main() {
	WeirdTriangle wt;
	cout << wt.findAllTriangle(200000, {}, 777818934, 1000000000) << endl;;
	// cout << wt.findAllTriangle(4, {1, 4, 6}, 200, 100) << endl;;
	return 0;
}
