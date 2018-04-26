#include <bits/stdc++.h>
using namespace std;

class LFUCache {
	struct Freq;
	struct Item {
		int val, key;
		Item *pre, *nxt;
		Freq *flist;
	};
	struct Freq {
		Freq(int freq) {
			f = freq;
			cnt = 0;
			head = new Item();
			tail = new Item();
			head->flist = tail->flist = this;
			head->pre = tail->nxt = nullptr;
			head->nxt = tail;
			tail->pre = head;
		}
		~Freq() {
			for (auto *p=head; p!=nullptr; ) {
				auto *cur = p;
				p = p->nxt;
				delete p;
			}
		}
		int f, cnt;
		Freq *high, *low;
		Item *head, *tail;
	} *mxf, *mnf;

	void remove_freq(Freq *freq) {
		auto *high = freq->high, *low = freq->low;
		high->low = low;
		low->high = high;
	}

	void add_freq(Freq *high, Freq *freq) {
		auto *low = high->low;
		high->low = freq;
		freq->high = high;
		freq->low = low;
		low->high = freq;
	}

	void remove_item(Item *item) {
		auto *flist = item->flist;
		--flist->cnt;
		auto *pre = item->pre;
		auto *nxt = item->nxt;
		pre->nxt = nxt;
		nxt->pre = pre;
		if (flist->cnt == 0) {
			remove_freq(flist);
		}
	}

	void add_item(Item *pre, Item *item) {
		auto *nxt = pre->nxt;
		auto *flist = pre->flist;
		++flist->cnt;
		pre->nxt = item;
		item->pre = pre;
		item->nxt = nxt;
		nxt->pre = item;
		item->flist = flist;
	}

	int cap, tot;
	unordered_map<int, Item*> hm;
public:
    LFUCache(int capacity) {
		cap = capacity;
		tot = 0;
		mxf = new Freq(0x7fffffff);
		mnf = new Freq(0);
		mxf->high = mnf->low = nullptr;
		mxf->low = mnf;
		mnf->high = mxf;
    }

	~LFUCache() {
		for (auto *p=mxf; p!=nullptr; ) {
			auto *cur = p;
			p = p->low;
			delete cur;
		}
	}

    int get(int key) {
		auto it = hm.find(key);
		if (it == hm.end()) { return -1; }
		auto *pi = it->second;
		auto *pl = pi->flist;
		int f = pl->f + 1;
		auto *high = pl->high;
		remove_item(pi);
		if (high->f > f) {
			Freq *freq = new Freq(f);
			add_freq(high, freq);
			high = freq;
		}
		add_item(high->head, pi);
		return pi->val;
    }
    
    void put(int key, int value) {
		if (get(key) != -1) {
			auto it = hm.find(key);
			it->second->val = value;
			return;
		}
		if (cap == 0) { return; }
		if (tot == cap) {
			--tot;
			auto *lf = mnf->high;
			auto *lf_i = lf->tail->pre;
			remove_item(lf_i);
			hm.erase(lf_i->key);
			delete lf_i;
		}

		++tot;
		auto *low = mnf->high;
		if (low->f != 1) {
			auto *tmp = new Freq(1);
			add_freq(low, tmp);
			low = tmp;
		}

		auto *item = new Item();
		item->val = value;
		item->key = key;
		add_item(low->head, item);
		hm[key] = item;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
	int n; cin >> n;
	LFUCache cache(n);
	int c, v;
	while (cin >> c >> v) {
		if (c == 1) {
			int vv; cin >> vv;
			cache.put(v, vv);
		} else {
			cout << cache.get(v) << endl;
		}
	}

	return 0;
}
