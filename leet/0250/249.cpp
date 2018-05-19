class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) { 
		unordered_map<string, int> hm;
		unordered_map<string, int> vhm;
		for (auto &s: strings) {
			++hm[s];
			vhm[s] = false;
		}

		vector<vector<string>> ans;
		for (auto &kvp: vhm) {
			if (kvp.second) { continue; }
			kvp.second = true;
			vector<string> buff;
			for (int i=0, ed=hm[kvp.first]; i<ed; ++i) { buff.push_back(kvp.first); }
			for (int i=1; i<26; ++i) {
				string tmp = kvp.first;
				for (int j=0; j<int(tmp.length()); ++j) {
					tmp[j] = ((tmp[j]-'a'+i) % 26) + 'a';
				}

				auto it = vhm.find(tmp);
				if (it != hm.end()) {
					it->second = true;
					for (int j=0, ed=hm[it->first]; j<ed; ++j) {
						buff.emplace_back(tmp);
					}
				}
			}
			ans.emplace_back(move(buff));
		}
		return ans;
	}
};
