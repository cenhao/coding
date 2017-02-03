#include <cstdlib>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
	public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode *cur = root;

		while (cur != NULL) {
			for (TreeLinkNode *it=cur; it!=NULL; it=it->next) {
				if (it->left == NULL) { break; }
				it->left->next = it->right;
				TreeLinkNode *r = it->left->right, *l=it->right->left;
				while (r != NULL) {
					r->next = l;
					r = r->right; l = l->left;
				}
			}

			cur = cur->left;
		}
	}
};
