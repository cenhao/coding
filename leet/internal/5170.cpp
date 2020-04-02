class Solution {
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		vector<int> f(n);
		vector<int> vis(n, false);
		for (int i=0; i<n; ++i) { f[i] = i; }
		function<int(int)> find = [&](int x) { return f[x] = (f[x] == f[f[x]] ? f[x] : find(f[x])); };

		function<bool(int, int)> traverse = [&](int cur, int par) {
			if (vis[cur]) { return false; }
			vis[cur] = true;
			f[cur] = par;

			if (leftChild[cur] != -1) {
				if (!traverse(leftChild[cur], par)) { return false; }
			}
			if (rightChild[cur] != -1) {
				if (!traverse(rightChild[cur], par)) { return false; }
			}

			return true;
		};

		for (int i=0; i<n; ++i) {
			if (f[i] == i) {
				if (!traverse(i, i)) { return false; }
			}
		}

		int root = -1;
		for (int i=0; i<n; ++i) {
			int tr = find(i);
			if (root == -1) {
				root = tr;
			} else if (root != tr) {
				return false;
			}
		}

		return true;
	}
};
