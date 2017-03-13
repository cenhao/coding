#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* str2tree(string s) {
		string ss = "(" + s + ")";
		int idx = 0;
		return proc(ss, idx);
	}

	TreeNode* proc(const string &s, int &st) {
		++st; // (
		bool read = false;
		bool neg = false;
		int v = 0;
		for ( ; st<s.length() && ((s[st]>='0' && s[st]<='9') || (!neg && s[st] == '-')); ++st) {
			read = true;
			if (s[st] == '-') {
				neg = true;
				continue;
			}
			v = v * 10 + s[st]-'0';
		}

		if (!read) { return NULL; }
		if (neg) v = -v;
		TreeNode *node = new TreeNode(v);

		if (st < s.length() && s[st] == '(') {
			node->left = proc(s, st);
		}
		if (st < s.length() && s[st] == '(') {
			node->right = proc(s, st);
		}

		++st; // )

		return node;
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	sol.str2tree(s);
	return 0;
}

