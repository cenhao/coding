class HitCounter {
private:
	list<pair<int, int>> q;
	int tot;
public:
    /** Initialize your data structure here. */
    HitCounter() {
		tot = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
		if (q.empty() || q.begin()->first!=timestamp) {
			q.push_front(make_pair(timestamp, 0));
		}
		++q.begin()->second;
		++tot;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
		while (!q.empty() && q.back().first <= timestamp-300) {
			tot -= q.back().second;
			q.pop_back();
		}
		return tot;
    }
};

class HitCounter {
private:
	pair<int, int> p[301];
	int tot, h, r;
public:
	HitCounter() {
		tot = 0;
		h = r = 0;
		p[r].first = p[r].second = 0;
	}

	void hit(int ts) {
		int idx = (h-1+301) % 301;
		if (h == r || p[idx].first!=ts) {
			int nidx = (h+1) % 301;
			if (nidx == r) {
				tot -= p[r].second;
				r = (r+1) % 301;
			}
			p[h].first = ts;
			p[h].second = 0;
			idx = h;
			h = nidx;
		}
		++p[idx].second;
		++tot;
	}

	int getHits(int ts) {
		while (r!=h && p[r].first<=ts-300) {
			tot -= p[r].second;
			r = (r+1) % 301;
		}

		return tot;
	}
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
