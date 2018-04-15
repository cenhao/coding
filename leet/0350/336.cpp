class Solution {
public:
	struct TrieNode {
		TrieNode() {
			memset(lnk, -1, sizeof(lnk));
			wid = -1;
		}
		int lnk[26];
		int wid;
		vector<int> ok_child;
	};

	void insert_word(const string &w, vector<TrieNode> &nodes, int id, const vector<bool> &fok) {
		int cur = 0, len = w.length();;
		for (int i=len-1; i>=0; --i) {
			if (fok[i]) { nodes[cur].ok_child.push_back(id); }
			int idx = w[i] - 'a';
			if (nodes[cur].lnk[idx] == -1) {
				nodes.emplace_back();
				nodes[cur].lnk[idx] = nodes.size()-1;
			}
			cur = nodes[cur].lnk[idx];
		}

		nodes[cur].wid = id;
	}

	void manacher(const string &w, vector<vector<bool>> &fdp, vector<vector<bool>> &bdp) {
		int len = w.length();
		string tmp(2*len+2, ' ');
		vector<int> dp(2*len+2, 0);
		tmp[0] = 1; tmp[1] = 0;
		dp[0] = 1; dp[1] = 1;
		for (int i=0; i<len; ++i) {
			tmp[2+i*2] = w[i];
			tmp[2+i*2+1] = 0;
		}

		int ctr = 1;
		for (int i=2, end=2+len*2; i<end; ++i) {
			if (tmp[ctr-(i-ctr)] == tmp[i]) {
				++dp[ctr];
			} else {
				int octr = ctr++;
				for (; ctr<i; ++ctr) {
					dp[ctr] = min(dp[octr-(ctr-octr)], i-ctr);
					if (ctr+dp[ctr]==i && tmp[i]==tmp[ctr-(i-ctr)]) { break; }
				}
				++dp[ctr];
			}
		}
		int octr = ctr;
		for (int end=2+len*2; ctr<end; ++ctr) {
			dp[ctr] = min(dp[octr-(ctr-octr)], end-1-ctr);
		}
		vector<bool> fok(len, false), bok(len, false);
		for (int i=2, end=len*2; i<=end; ++i) {
			if (i+dp[i]-1>=end) {
				bok[(i-(end-i)-2)>>1] = true;
			}
			if (i-dp[i]+1<=2) {
				fok[(i+(i-2)-2)>>1] = true;
			}
		}

		fdp.push_back(move(fok));
		bdp.push_back(move(bok));
	}

	vector<vector<int>> palindromePairs(vector<string>& words) {
		int sz = words.size();
		vector<vector<bool>> par_fdp;
		vector<vector<bool>> par_bdp;
		vector<TrieNode> nodes;
		nodes.emplace_back();
		for (int i=0; i<sz; ++i) {
			manacher(words[i], par_fdp, par_bdp);
			insert_word(words[i], nodes, i, par_fdp[i]);
		}

		vector<vector<int>> ans;
		for (int i=0; i<sz; ++i) {
			int len = words[i].length();
			int cur = 0;
			for (int j=0; j<len; ++j) {
				int idx = words[i][j] - 'a';
				if (nodes[cur].lnk[idx] == -1) {
					cur = -1;
					break;
				}
				cur = nodes[cur].lnk[idx];
				if (nodes[cur].wid >= 0) {
					if ((j==len-1 || par_bdp[i][j+1]) && i!=nodes[cur].wid) {
						vector<int> tmp = { i, nodes[cur].wid };
						ans.push_back(move(tmp));
					}
				}
			}

			if (len == 0) {
				for (int j=0; j<sz; ++j) {
					if (i!=j && par_bdp[j][0]) {
						vector<int> tmp = { j, i };
						ans.push_back(move(tmp));
					}
				}
			}

			if (cur != -1) {
				for (auto c: nodes[cur].ok_child) {
					if (c == i) { continue; }
					vector<int> tmp = { i, c };
					ans.push_back(move(tmp));
				}
			}
		}

		return ans;
	}
};
