/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
	list<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> stk;

	bool init(const vector<NestedInteger> &nestedList) {
		for (auto it=nestedList.begin(); it!=nestedList.end(); ++it) {
			stk.push_back(make_pair(it, nestedList.end()));
			if (it->isInteger()) { return true; }
			const auto &snl = it->getList();
			if (init(snl)) { return true; }
			stk.pop_back();
		}
		return false;
	}

	bool moveNext(vector<NestedInteger>::const_iterator it, vector<NestedInteger>::const_iterator ed) {
		for (auto i=it; i!=ed; ++i) {
			stk.push_back(make_pair(i, ed));
			if (i->isInteger()) { return true; }
			const auto &snl = i->getList();
			if (moveNext(snl.begin(), snl.end())) { return true; }
			stk.pop_back();
		}
		return false;
	}

    NestedIterator(vector<NestedInteger> &nestedList) {
		init(nestedList);
    }

    int next() {
		auto p = stk.back();
		stk.pop_back();
		int ret = p.first->getInteger();
		++p.first;
		while (!moveNext(p.first, p.second) && !stk.empty()) {
			p = stk.back();
			stk.pop_back();
			++p.first;
		}
		return ret;
    }

    bool hasNext() {
		return !stk.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
