#include <cstdlib>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/*
class Solution {
	public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) { return NULL; }

		RandomListNode *clone = NULL;
		for (RandomListNode *cur=head; cur!=NULL; cur=cur->next->next) {
			RandomListNode *pn;
			if (clone == NULL) {
				clone = pn = new RandomListNode(cur->label);
			} else {
				pn = new RandomListNode(cur->label);
			}

			pn->next = cur->next;
			cur->next = pn;
		}

		for (RandomListNode *cur=head; cur!=NULL; cur=cur->next->next) {
			RandomListNode *pn = cur->next;
			pn->random = cur->random == NULL ? NULL : cur->random->next;
		}

		for (RandomListNode *cur=head; cur!=NULL; cur=cur->next) {
			RandomListNode *pn = cur->next;
			RandomListNode *tmp = pn->next;
			pn->next = tmp == NULL ? NULL : tmp->next;
			cur->next = tmp;
		}

		return clone;
	}
};
*/

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr) { return head; }
		for (RandomListNode *ptr=head; ptr!=nullptr; ptr=ptr->next) {
			auto *tmp = new RandomListNode(ptr->label);
			tmp->next = tmp->random = ptr->random;
			ptr->random = tmp;
		}
		for (RandomListNode *ptr=head; ptr!=nullptr; ptr=ptr->next) {
			auto *cur = ptr->random; // copy
			cur->random = cur->random == nullptr ? nullptr : cur->random->random;
		}
		RandomListNode vh(0);
		for (RandomListNode *ptr=head, *cur=&vh; ptr!=nullptr; ptr=ptr->next) {
			cur = cur->next = ptr->random;
			ptr->random = cur->next;
			cur->next = ptr->next == nullptr ? nullptr : ptr->next->random;
		}

		return vh.next;
	}
};

int main() {
	RandomListNode rn(-1);
	RandomListNode rn1(8);
	RandomListNode rn2(7);
	RandomListNode rn3(-3);
	RandomListNode rn4(4);
	rn.next = &rn1;
	rn1.next = &rn2;
	rn2.next = &rn3;
	rn3.next = &rn4;
	rn.random = &rn4; rn4.random = &rn;
	rn1.random = &rn3;
	Solution sol;
	RandomListNode *pn = sol.copyRandomList(&rn);
	delete pn;
	return 0;
}
