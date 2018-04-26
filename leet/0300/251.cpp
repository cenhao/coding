class Vector2D {
	vector<vector<int>>::iterator rit, ed, pre;
	vector<int>::iterator cit, pcit;
public:
    Vector2D(vector<vector<int>>& vec2d) {
		rit = vec2d.begin(), ed = pre = vec2d.end();
		while (rit!=ed) {
			cit = rit->begin();
			if (cit != rit->end()) { break; }
			++rit;
		}
    }

    int next() {
		pre = rit; pcit = cit;
		int ret = *cit;
		++cit;
		if (cit == rit->end()) {
			++rit;
			while (rit != ed) {
				cit = rit->begin();
				if (cit != rit->end()) { break; }
				++rit;
			};
		}
		return ret;
    }

    bool hasNext() {
		return rit != ed;
    }

	void remove() {
		if (pre != ed) {
			pre->erase(pcit);
			if (pre == rit) {
				--cit;
			}
		}
	}
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
