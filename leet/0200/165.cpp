class Solution {
public:
	vector<int> parse(const string &v) {
		string tmp = "";
		vector<int> ret;
		for (int i=0; i<=v.length(); ++i) {
			if (i == v.length() || v[i] == '.') {
				ret.emplace_back(stoi(tmp));
				tmp = "";
			} else {
				tmp += v[i];
			}
		}

		return ret;
	}
	int compareVersion(string version1, string version2) {
		vector<int> v1 = move(parse(version1));
		vector<int> v2 = move(parse(version2));

		for (int i=0, end=max(v1.size(), v2.size()); i<end; ++i) {
			int n1 = i >= v1.size() ? 0 : v1[i];
			int n2 = i >= v2.size() ? 0 : v2[i];
			if (n1 != n2) { return n1 < n2 ? -1 : 1; }
		}
		return 0;
	}
};
