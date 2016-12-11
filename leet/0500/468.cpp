#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	string validIPAddress(string IP) {
		static char buff[32768];
		int cdot = 0;
		int ccol = 0;
		bool haschar = false;
		bool illegal = false;
		char last = 0;
		for (int i=0, end=IP.length(); i<end && !illegal; ++i) {
			char c = IP[i];
			if (c == '.') ++cdot;
			else if (c == ':') ++ ccol;
			else if (c >= 'a' && c <= 'f') { haschar = true; }
			else if (c >= 'A' && c <= 'F') { haschar = true; }
			else if (c < '0' || c > '9') { illegal = true; }

			if (c == ':' && last == c) { illegal = true; }
			last = c;
		}

		if (cdot && ccol) { illegal = true; }
		if (cdot && haschar) { illegal = true; }
		if (illegal ||
			(ccol != 7 && cdot == 0) ||
			(cdot != 3 && ccol == 0)) {
			return "Neither";
		}

		if (cdot) {
			sprintf(buff, "%s", IP.c_str());
			char *tmp = buff;
			char *seg;
			while (seg = strtok(tmp, ".")) {
				tmp = NULL;
				if ((seg[0] == '0' && seg[1] != 0) || strlen(seg) > 3) {
					return "Neither";
				}
				int v;
				sscanf(seg, "%d", &v);
				if (v > 255) { return "Neither"; }
			}
		} else {
			sprintf(buff, "%s", IP.c_str());
			char *tmp = buff;
			char *seg;
			while (seg = strtok(tmp, ":")) {
				tmp = NULL;
				if (strlen(seg) > 4) { return "Neither"; }
			}
		}

		if (cdot) { return "IPv4"; }
		return "IPv6";
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	cout << sol.validIPAddress(s) << endl;
	return 0;
}
