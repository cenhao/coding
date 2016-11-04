#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			static string letter[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			vector<string> result;
			for (int i=0; i<digits.length(); ++i) {
				if (digits[i] == '0' || digits[i] == '1') { return result; }
			}
			if (digits.length() > 0) {
				string cur = "";
				dfs(0, digits, letter, cur, result);
			}
			return result;
		}

	private:
		void dfs(int idx, const string &digits, const string *letter, string &cur, vector<string> &result) {
			if (idx >= digits.length()) {
				result.push_back(cur);
			}
			int n = digits[idx] - '0';
			for (int i=0; i<letter[n].size(); ++i) {
				if (cur.length() <= idx) {
					cur += letter[n][i];
				} else {
					cur[idx] = letter[n][i];
				}

				dfs(idx+1, digits, letter, cur, result);
			}
		}
};
