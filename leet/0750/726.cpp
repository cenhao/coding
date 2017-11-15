class Solution {
public:
	int process(const string &f, int p, unordered_map<string, int> &em) {
		for (; p<f.length() && f[p]!=')'; ++p) {
			if (f[p] == '(') {
				unordered_map<string, int> nem;
				p = process(f, p+1, nem) + 1;

				int cnt = 0;
				while (p < f.length() && f[p] >= '0' && f[p] <= '9') {
					cnt = cnt * 10 + f[p++]-'0';
				}
				if (cnt == 0) { cnt = 1; }
				for (auto &ent : nem) { em[ent.first] += ent.second * cnt; }
				--p;
			} else {
				string cur = "";
				cur += f[p++];
				while (p < f.length() && f[p] >= 'a' && f[p] <= 'z') { cur += f[p++]; }
				int cnt = 0;
				while (p < f.length() && f[p] >= '0' && f[p] <= '9') {
					cnt = cnt * 10 + f[p++]-'0';
				}
				if (cnt == 0) { cnt = 1; }
				em[cur] += cnt;
				--p;
			}
		}

		return p;
	}

	string countOfAtoms(string formula) {
		unordered_map<string, int> em;
		process(formula, 0, em);
		map<string, int> sem;
		for (auto &ent : em) { sem[ent.first] = ent.second; }
		string ans = "";
		for (auto &ent : sem) {
			ans += ent.first;
			if (ent.second > 1) {
				ans += to_string(ent.second);
			}
		}

		return ans;
	}
};
