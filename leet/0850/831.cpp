#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool is_email(const string &s) {
		return s.find('@') != string::npos;
	}
	string process_email(const string &s) {
		int idx = s.find('@');
		string name = s.substr(0, idx);
		string suffix = s.substr(idx+1);
		for (auto &c: suffix) { c = tolower(c); }
		for (auto &c: name) { c = tolower(c); }
		string tmp = name;
		if (name.length() >= 2) {
			tmp = name[0];
			tmp += "*****";
			tmp += name[name.length()-1];
		}
		return tmp + "@" + suffix;
	}
	string process_phone(const string &s) {
		string buf;
		for (auto c: s) {
			if (c>='0' && c<='9') { buf += c; }
		}
		int len = buf.length();
		if (len > 10) {
			int ext = len - 10;
			string ret = "+";
			for (int i=0; i<ext; ++i) { ret += '*'; }
			ret += "-***-***-";
			ret += buf.substr(len-4);
			return ret;
		} else {
			return "***-***-" + buf.substr(6);
		}
	}
	string maskPII(string s) {
		if (is_email(s)) {
			return process_email(s);
		}
		return process_phone(s);
	}
};

int main() {
	string s;
	while (cin >> s) {
		Solution sol;
		cout << sol.maskPII(s) << endl;
	}
	return 0;
}
