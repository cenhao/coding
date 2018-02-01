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
/*
 * another attempt
class Solution {
	public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode vh(0), *cur = root;
		while (cur != nullptr) {
			TreeLinkNode *nxt = &vh, *tmp = &vh;
			for (auto *i=cur; i!=nullptr; i=i->next) {
				if (i->left != nullptr) {
					tmp->next = i->left;
					tmp = tmp->next;
				}
				if (i->right != nullptr) {
					tmp->next = i->right;
					tmp = tmp->next;
				}
			}
			cur = nxt->next; nxt->next = nullptr;
		}
	}
};
*/
