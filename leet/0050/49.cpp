class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> hm;
		for (auto &str: strs) {
			string cp = str;
			sort(cp.begin(), cp.end());
			auto it = hm.find(cp);
			if (it == hm.end()) {
				it = hm.insert(make_pair(cp, vector<string>())).first;
			}

			it->second.push_back(move(str));
		}

		vector<vector<string>> ans;
		for (auto &ent: hm) {
			ans.push_back(move(ent.second));
		}

		return ans;
	}
};
