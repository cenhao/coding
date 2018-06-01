class ZigzagIterator {
	vector<int>::iterator it[2], ed[2];
	int cur;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		it[0] = v1.begin();
		it[1] = v2.begin();
		ed[0] = v1.end();
		ed[1] = v2.end();
		cur = 0;
    }

    int next() {
		if (it[cur] == ed[cur]) {
			cur = (cur + 1) & 1;
		}
		int ret = *it[cur];
		++it[cur];
		cur = (cur + 1) & 1;
		return ret;
    }

    bool hasNext() {
		return it[0]!=ed[0] || it[1]!=ed[1];
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
