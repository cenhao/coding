#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int clumsy(int N) {
		vector<int> vec(1, N);
		for (int i=N-1, cnt=0; i>0; --i, ++cnt) {
			int op = cnt % 4;
			if (op == 0) {
				vec[vec.size()-1] *= i;
			} else if (op == 1) {
				vec[vec.size()-1] /= i;
			} else if (op == 2) {
				vec.push_back(i);
			} else {
				vec.push_back(-i);
			}
		}

		int sm = 0;
		for (auto v: vec) { sm += v; }
		return sm;
	}
};

int main() {
	int n; cin >> n;
	while (cin >> n) {
		Solution sol;
		cout << sol.clumsy(n) << endl;
	}
	return 0;
}
