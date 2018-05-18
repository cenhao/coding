class Solution {
public:
	string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		string ans;
		unordered_map<int, int> hm;
		for (int i=0; i<indexes.size(); ++i) { hm[indexes[i]] = i; }
		for (int i=0; i<s.length(); ++i) {
			auto it = hm.find(i);
			if (it != hm.end()) {
				int idx = it->second, j;
				for (j=0; i+j<s.length() && j<sources[idx].length(); ++j) {
					if (sources[idx][j] != s[i+j]) { break; }
				}

				if (j == sources[idx].length()) {
					ans += targets[idx];
					i += sources[idx].length() - 1;
				} else {
					ans += s[i];
				}
			} else {
				ans += s[i];
			}
		}
		return ans;
	}
};
