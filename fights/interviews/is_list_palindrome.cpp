// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };

bool isListPalindrome(ListNode<int> *l) {
	if (l == nullptr) { return true; }

	ListNode<int> *ptr = l;
	int cnt = 0;

	while (ptr != nullptr) {
		++cnt;
		ptr = ptr->next;
	}

	int skip = (cnt-1) / 2;
	ptr = l;
	for (int i=0; i<skip; ++i) { ptr = ptr->next; }

	ListNode<int> *rptr = nullptr, *iptr = ptr->next, *tmp;
	while (iptr != nullptr) {
		tmp = iptr->next;
		iptr->next = rptr;
		rptr = iptr;
		iptr = tmp;
	}

	iptr = rptr; ptr = l;
	bool palindrome = true;
	while (iptr != nullptr) {
		if (iptr->value != ptr->value) {
			palindrome = false;
			break;
		}

		iptr = iptr->next;
		ptr = ptr->next;
	}

	iptr = rptr; rptr = nullptr;
	while (iptr != nullptr) {
		tmp = iptr->next;
		iptr->next = rptr;
		rptr = iptr;
		iptr = tmp;
	}

	return palindrome;
}
