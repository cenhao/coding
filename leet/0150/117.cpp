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
		TreeLinkNode tmp(0);

		while (cur != NULL) {
			TreeLinkNode *tail = &tmp, *head = &tmp; head->next = NULL;
			for (TreeLinkNode *it=cur; it!=NULL; it=it->next) {
				if (it->left != NULL) {
					tail->next = it->left;
					tail = tail->next;
				}
				if (it->right != NULL) {
					tail->next = it->right;
					tail = tail->next;
				}
			}

			cur = head->next;
		}
	}
};
