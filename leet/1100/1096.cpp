class Solution {
public:
	vector<string> flatten(vector<vector<string>> &in) {
		unordered_set<string> hs;
		for (auto &&vs: in) {
			for (auto &&s: vs) { hs.emplace(move(s)); }
		}
		return move(vector<string>(hs.begin(), hs.end()));
	}

	vector<string> cross(vector<string> &vs1, vector<string> &vs2) {
		vector<string> ret;
		for (auto &s1: vs1) {
			for (auto &s2: vs2) { ret.emplace_back(move(s1 + s2)); }
		}
		return move(ret);
	}

	vector<string> dfs(string &exp, int &cur) {
		vector<vector<string>> tmp;
		bool merge = true;
		for (; cur<exp.length(); ++cur) {
			vector<string> ret;
			if (exp[cur] == ',') {
				merge = false;
				continue;
			} else if (exp[cur] == '}') {
				break;
			} else if (exp[cur] == '{') {
				++cur;
				vector<string> sub;
				ret = move(dfs(exp, cur));
			} else {
				ret = vector<string> { string(1, exp[cur]) };
			}
			if (merge) {
				int len = tmp.size();
				if (len == 0) {
					tmp.emplace_back(move(ret));
				} else {
					tmp[len-1] = move(cross(tmp[len-1], ret));
				}
			} else {
				tmp.emplace_back(move(ret));
			}
			merge = true;
		}

		return move(flatten(tmp));
	}

	vector<string> braceExpansionII(string expression) {
		int cur = 0;
		auto ret = move(dfs(expression, cur));
		sort(ret.begin(), ret.end());
		return ret;
	}
};

