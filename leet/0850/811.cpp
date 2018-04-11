class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> hm;
		for (auto &d: cpdomains) {
			int fsp = d.find_first_of(' ');
			int cnt = stoi(d.substr(0, fsp)), len = d.length();
			while (d[fsp] == ' ') { ++fsp; }
			for (int i=fsp, last=fsp; i<=len; ++i) {
				if (i==len || d[i]=='.') {
					hm[d.substr(last)] += cnt;
					last = i+1;
				}
			}
		}

		vector<string> ans;
		for (auto &kvp: hm) {
			ans.push_back(move(to_string(kvp.second) + " " + kvp.first));
		}
		return ans;
	}
};
