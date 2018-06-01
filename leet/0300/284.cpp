// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
	int buf;
	bool buf_init;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if (Iterator::hasNext()) {
			buf = Iterator::next();
			buf_init = true;
		} else {
			buf_init = false;
		}
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() { return buf; }

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int ret = buf;
		if (Iterator::hasNext()) {
			buf = Iterator::next();
		} else {
			buf_init = false;
		}
		return ret;
	}

	bool hasNext() const { return buf_init; }
};
