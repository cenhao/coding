class Solution {
public:
	struct Node {
		Node() { exist = false; }
		unordered_map<string, Node*> children;
		bool exist;
	};

	void dfs(Node *cur, string buf, vector<string> &ans) {
		if (cur->exist) {
			ans.emplace_back(buf);
			return;
		}
		buf += '/';
		for (auto &kvp: cur->children) {
			dfs(kvp.second, buf + kvp.first, ans);
		}
	}

	vector<string> removeSubfolders(vector<string>& folders) {
		Node root;
		for (auto &f: folders) {
			int len = f.length();
			string buf;
			Node *pcur = &root;
			for (int i=1; i<=len; ++i) {
				if (i==len || f[i]=='/') {
					auto it = pcur->children.find(buf);
					if (it == pcur->children.end()) {
						it = pcur->children.emplace(buf, new Node()).first;
					}
					pcur = it->second;
					buf = "";
				} else {
					buf += f[i];
				}
			}

			pcur->exist = true;
		}

		vector<string> ans;
		dfs(&root, string(""), ans);
		return ans;
	}
};
