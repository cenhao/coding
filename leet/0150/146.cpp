class LRUCache {
public:
	struct TimeRecord {
		TimeRecord *pre, *nxt;
		int id;
	} head, tail;
	struct Data {
		TimeRecord *tr;
		int val;
	};
    LRUCache(int capacity) {
		head.pre = tail.nxt = nullptr;
		head.nxt = &tail;
		tail.pre = &head;
		cap = capacity;
    }
    
    int get(int key) {
		auto it = hm.find(key);
		if (it == hm.end()) {
			return -1;
		}

		update(it->second.tr);
		return it->second.val;
    }
    
    void put(int key, int value) {
		auto it = hm.find(key);
		if (it != hm.end()) {
			it->second.val = value;
			update(it->second.tr);
			return;
		}
		if (cap == hm.size()) {
			auto *ltr = tail.pre;
			remove(ltr);
			hm.erase(ltr->id);
			delete ltr;
		}

		TimeRecord *tr = new TimeRecord();
		tr->id = key;
		add(tr);
		Data d = { tr, value };
		hm.insert(make_pair(key, d));
    }
private:
	unordered_map<int, Data> hm;
	int cap;
	void update(TimeRecord *tr) {
		remove(tr);
		add(tr);
	}
	void remove(TimeRecord *tr) {
		tr->pre->nxt = tr->nxt;
		tr->nxt->pre = tr->pre;
	}

	void add(TimeRecord *tr) {
		tr->nxt = head.nxt;
		tr->pre = &head;
		head.nxt->pre = tr;
		head.nxt = tr;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
