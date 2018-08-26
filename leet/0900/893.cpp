class Solution {
public:
	int numSpecialEquivGroups(vector<string>& a) {
		unordered_set<string> hs;
		for (auto &s: a) {
			string proc[2];
			for (int i=0; i<s.length(); ++i) { proc[i&1] += s[i]; }
			sort(proc[0].begin(), proc[0].end());
			sort(proc[1].begin(), proc[1].end());
			hs.emplace(move(proc[0]+proc[1]));
		}
		return (int) hs.size();
	}
};
