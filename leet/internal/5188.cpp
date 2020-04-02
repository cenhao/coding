#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
	struct Node {
		vector<int> children;
		vector<int> ancestors;
	};
	vector<Node> nodes;

	void traverse(int cur) {
		int p = nodes[cur].ancestors[0];
		int cnt = 0;
		while (p != -1) {
			int np;
			if (cnt >= nodes[p].ancestors.size()) {
				np = -1;
			} else {
				np = nodes[p].ancestors[cnt];
			}
			nodes[cur].ancestors.push_back(np);
			p = np;
			++cnt;
		}

		for (auto c: nodes[cur].children) {
			traverse(c);
		}
	}

    TreeAncestor(int n, vector<int>& parent) {
		nodes.resize(n);
		for (int i=0; i<n; ++i) {
			if (parent[i] == -1) {
				nodes[i].ancestors.push_back(-1);
			} else {
				nodes[parent[i]].children.push_back(i);
				nodes[i].ancestors.push_back(parent[i]);
			}
		}

		traverse(0);
    }
    
    int getKthAncestor(int node, int k) {
		int cur = node;
		for (int i=31; i>=0; --i) {
			if (!(k & (1<<i))) { continue; }
			if (i >= nodes[cur].ancestors.size() || nodes[cur].ancestors[i]==-1) { return -1; }
			cur = nodes[cur].ancestors[i];
		}
		return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main() {
	vector<int> p = {-1, 0, 0, 1, 2};
	TreeAncestor ta(5, p);
	cout << ta.getKthAncestor(3, 5) << endl;
	cout << ta.getKthAncestor(3, 2) << endl;
	cout << ta.getKthAncestor(2, 2) << endl;
	cout << ta.getKthAncestor(0, 2) << endl;
	cout << ta.getKthAncestor(2, 1) << endl;
	return 0;
}
