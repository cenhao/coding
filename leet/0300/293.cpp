class Solution {
public:
	vector<string> generatePossibleNextMoves(string s) {
		vector<string> ans;
		for (int i=0; i<int(s.length())-1; ++i) {
			if (s[i]=='+' && s[i+1]=='+') {
				string tmp = s;
				tmp[i] = tmp[i+1] = '-';
				ans.emplace_back(move(tmp));
			}
		}
		return ans;
	}
};
