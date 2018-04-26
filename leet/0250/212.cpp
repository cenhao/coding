class Solution {
public:
	struct TrieNode {
		TrieNode() {
			memset(lnk, -1, sizeof(lnk));
			word = -1;
		}
		int lnk[26];
		int word;
	};
	void insert(const string &w, int id, vector<TrieNode> &nodes, int root) {
		int len = w.length();
		int cur = root;
		for (int i=0; i<len; ++i) {
			int idx = w[i] - 'a';
			if (nodes[cur].lnk[idx] == -1) {
				nodes[cur].lnk[idx] = nodes.size();
				nodes.emplace_back();
			}
			cur = nodes[cur].lnk[idx];
		}
		nodes[cur].word = id;
	}
	void dfs(int x, int y, vector<TrieNode> &nodes, vector<vector<char>> &b, vector<vector<bool>> &vis, int cur, unordered_set<int> &hit) {
		const static int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		if (nodes[cur].word >= 0) { hit.insert(nodes[cur].word); }
		int rsz = b.size(), csz = b[0].size();
		vis[x][y] = true;
		for (int i=0; i<4; ++i) {
			int xx = x + mov[i][0], yy = y + mov[i][1];
			if (xx<0 || xx>=rsz || yy<0 || yy>=csz || vis[xx][yy] || nodes[cur].lnk[b[xx][yy]-'a']==-1) {
				continue;
			}
			dfs(xx, yy, nodes, b, vis, nodes[cur].lnk[b[xx][yy]-'a'], hit);
		}
		vis[x][y] = false;
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<TrieNode> nodes(1);
		for (int i=0; i<words.size(); ++i) { insert(words[i], i, nodes, 0); }
		int rsz = board.size(), csz = board[0].size();
		vector<vector<bool>> vis(rsz, vector<bool>(csz, false));
		unordered_set<int> hit;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				int idx = board[i][j]-'a';
				if (nodes[0].lnk[idx] == -1) { continue; }
				dfs(i, j, nodes, board, vis, nodes[0].lnk[idx], hit);
			}
		}
		vector<string> ans;
		for (auto i: hit) { ans.push_back(words[i]); }
		return ans;
	}
};
