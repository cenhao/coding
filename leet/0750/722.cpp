class Solution {
public:
	vector<string> removeComments(vector<string>& source) {
		int sz = source.size();
		int st = 0; // 0 normal, 1 pd, 2 line, 3 bk
		vector<string> ans;
		for (int i=0; i<sz; ++i) {
			bool con = (st == 3);
			string tmp;
			for (int j=0; j<source[i].length(); ++j) {
				if (source[i][j] != '/' && source[i][j] != '*') {
					if (st == 0) {
						tmp += source[i][j];
					} else if (st == 1) {
						tmp += '/';
						tmp += source[i][j];
						st = 0;
					} else if (st == 4) {
						st = 3;
					}
				} else if (source[i][j] == '/') {
					if (st == 0) {
						st = 1;
					} else if (st == 1) {
						st = 2;
					} else if (st == 4) {
						st = 0;
					}
				} else {
					if (st == 0) {
						tmp += '*';
					} else if (st == 1) {
						st = 3;
					} else if (st == 2) {
						continue;
					} else if (st == 3) {
						st = 4;
					}
				}
			}

			if (st == 2) { st = 0; }
			if (st == 1) {
				tmp += '/';
				st = 0;
			}
			if (st == 4) { st = 3; }
			if (tmp.length() > 0) {
				if (con) {
					ans[ans.size()-1] += tmp;
				} else {
					ans.push_back(tmp);
				}
			}
		}

		return ans;
	}
};
