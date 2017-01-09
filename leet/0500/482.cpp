#include <cctype>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	string licenseKeyFormatting(string S, int K) {
		int len = 0;
		for (int i=0, end=S.length(); i<end; ++i) {
			if (S[i] != '-') { ++len; }
		}

		int remainder = len % K;
		if (remainder == 0) { remainder = K; }

		string out = "";

		for (int i=0, end=S.length(), cnt = 0; i<end; ++i) {
			if (S[i] == '-') { continue; }
			if (remainder == K && cnt != 0) { out += '-'; }
			out += toupper(S[i]);
			++cnt; 
			if ((--remainder) == 0) { remainder = K; }
		}

		return out;
	}
};

int main() {
	string s; int k;
	while (cin >> s >> k) {
		Solution sol;
		cout << sol.licenseKeyFormatting(s, k) << endl;
	}

	return 0;
}
