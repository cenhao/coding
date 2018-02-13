#include <bits/stdc++.h>
using namespace std;

vector<int> revisedRussianRoulette(vector<int> doors) {
	vector<int> ans(2, 0);
	int sz = doors.size();
	for (int i=0; i<sz; ++i) {
		if (doors[i] != 0) { ++ans[1]; }
		if (doors[i] == 1) {
			++ans[0];
			if (i<sz-1 && doors[i+1] == 1) { doors[i+1] = 2; }
		}
	}

	return ans;
}

int main() {
    int n; cin >> n;
    vector<int> doors(n);
    for(int doors_i = 0; doors_i < n; doors_i++){ cin >> doors[doors_i]; }
    vector<int> result = revisedRussianRoulette(doors);

    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}

