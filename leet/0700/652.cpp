/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	struct Info { int id, cnt; };
	int process(TreeNode *cur, vector<TreeNode*> &ans, map<tuple<int, int, int>, Info> &cnts) {
		if (cur == nullptr) { return -1; }
		int lid = process(cur->left, ans, cnts);
		int rid = process(cur->right, ans, cnts);
		auto id = make_tuple(lid, cur->val, rid);
		auto it = cnts.find(id);
		if (it == cnts.end()) {
			Info tmp = { cnts.size(), 0 };
			it = cnts.insert(make_pair(id, tmp)).first;
		}
		++it->second.cnt;
		if (it->second.cnt == 2) { ans.push_back(cur); }
		return it->second.id;
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode *root) {
		vector<TreeNode*> ans;
		if (root == nullptr) { return ans; }
		map<tuple<int, int, int>, Info> cnts;
		process(root, ans, cnts);
		return ans;
	}
};
/*
class Solution {
public:
	unordered_map<TreeNode*, int> idmap;
	vector<int> f;
	map<int, vector<TreeNode*>> dmap;

	int find(int x) {
		if (f[x] != f[f[x]]) {
			f[x] = find(f[x]);
		}

		return f[x];
	}

	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		f[fy] = fx;
	}

	bool same(TreeNode *t1, TreeNode *t2, bool lookup) {
		if (t1 == nullptr) {
			return t2 == nullptr;
		} else {
			if (t2 == nullptr) { return false; }
		}

		if (lookup) { return find(idmap[t1]) == find(idmap[t2]); }
		if (t1->val != t2->val) { return false; }
		return same(t1->left, t2->left, true) && same(t1->right, t2->right, true);
	}

	int preprocess(TreeNode *cur) {
		if (cur == nullptr) { return 0; }
		int ld = preprocess(cur->left);
		int rd = preprocess(cur->right);
		int cur_id = idmap.size();
		idmap.insert(make_pair(cur, cur_id));
		f.push_back(cur_id);
		int d = max(ld, rd) + 1;
		auto it = dmap.find(d);
		if (it == dmap.end()) {
			it = dmap.insert(make_pair(d, vector<TreeNode*>())).first;
		}

		it->second.push_back(cur);
		return d;
	}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		vector<TreeNode*> ans;
		preprocess(root);
		for (auto it=dmap.begin(); it!=dmap.end(); ++it) {
			vector<bool> vis(it->second.size(), false);
			for (int i=0, end=it->second.size(); i<end; ++i) {
				if (vis[i]) { continue; }
				vis[i] = true;
				int scnt = 0;
				for (int j=i+1; j<end; ++j) {
					if (vis[j]) { continue; }
					if (same(it->second[i], it->second[j], false)) {
						vis[j] = true;
						merge(idmap[it->second[i]], idmap[it->second[j]]);
						++scnt;
					}
				}

				if (scnt > 0) { ans.push_back(it->second[i]); }
			}
		}

		return ans;
    }
};
*/
