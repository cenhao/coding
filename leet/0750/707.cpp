class MyLinkedList {
	struct Node {
		Node(int v, Node *p) { val = v; nxt = p; }
		int val;
		Node *nxt;
	};
	Node *head, *tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
		head = tail = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
		int val = -1, cnt = 0;;
		for (auto *ptr=head; ptr!=nullptr; ptr=ptr->nxt, ++cnt) {
			if (cnt == index) { return ptr->val; }
		}
		return val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
		if (head == nullptr) {
			head = tail = new Node(val, nullptr);
		} else {
			head = new Node(val, head);
		}
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
		if (head == nullptr) {
			head = tail = new Node(val, nullptr);
		} else {
			tail = tail->nxt = new Node(val, nullptr);
		}
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
		if (index == 0) {
			addAtHead(val);
		} else {
			int cnt = 0;
			bool added = false;
			for (Node *ptr=head, *pre=nullptr; ptr!=nullptr; pre=ptr, ptr=ptr->nxt, ++cnt) {
				if (cnt == index) {
					pre->nxt = new Node(val, ptr);
					added = true;
					break;
				}
			}

			if (cnt == index && !added) { addAtTail(val); }
		}
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
		int cnt = 0;
		for (Node *ptr=head, *pre=nullptr; ptr!=nullptr; pre=ptr, ptr=ptr->nxt, ++cnt) {
			if (cnt == index) {
				if (ptr == head) { head = ptr->nxt; }
				if (ptr == tail) { tail = pre; }
				if (pre != nullptr) { pre->nxt = ptr->nxt; }
				delete ptr;
				break;
			}
		}
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
