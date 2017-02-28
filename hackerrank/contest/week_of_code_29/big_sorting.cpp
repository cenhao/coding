#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define MAXN 200000
string nums[MAXN];

int main() {
	int n; cin >> n;
	for (int i=0; i<n; ++i) { cin >> nums[i]; }
	sort(nums, nums+n, [](const string &s1, const string &s2) -> bool {
		int is1; for (is1=0; is1<s1.length(); ++is1) { if (s1[is1] > '0') { break; } }
		int is2; for (is2=0; is2<s2.length(); ++is2) { if (s2[is2] > '0') { break; } }

		if (s1.length()-is1 != s2.length()-is2) {
			return s1.length()-is1 < s2.length()-is2;
		}

		for (int i=0, end=s1.length()-is1; i<end; ++i) {
			if  (s1[is1+i] != s2[is2+i]) { return s1[is1+i] < s2[is2+i]; }
		}

		return false;
	});

	for (int i=0; i<n; ++i) {
		cout << nums[i] << endl;
	}

	return 0;
}
