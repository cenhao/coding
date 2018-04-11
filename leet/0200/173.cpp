#include <cstdlib>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
	public:
		struct State {
			TreeNode *node;
			int lmr;
		};

		stack<State> states;

		BSTIterator(TreeNode *root) {
			if (root == NULL) { return ; }
			State state = { root, 0 };
			states.push(state);

			TreeNode *cur = root->left;;
			while (cur != NULL) {
				state.node = cur; state.lmr = 0;
				states.push(state);
				cur = cur->left;
			}
		}

		/** @return whether we have a next smallest number */
		bool hasNext() {
			return !states.empty();
		}

		/** @return the next smallest number */
		int next() {
			int ret = states.top().node->val;
			states.top().lmr = 1;

			TreeNode *cur = states.top().node->right;
			while (cur != NULL) {
				State state = { cur, 0 };
				states.push(state);
				cur = cur->left;
			}

			while (!states.empty() && states.top().lmr == 1) {
				states.pop();
			}

			return ret;
		}
};


// ---------------
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
		for (TreeNode *cur=root; cur!=nullptr; cur=cur->left) {
			stk.push(cur);
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
		auto p = stk.top(); stk.pop();
		for (auto *cur=p->right; cur!=nullptr; cur=cur->left) {
			stk.push(cur);
		}
		return p->val;
    }
private:
	stack<TreeNode*> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
