#include <bits/stdc++.h>
using namespace std;
class ExamRoom {
	struct EmptySeat {
		EmptySeat(int s, int p, int i) {
			space = s; pos = p; id = i;
		}
		int space, pos, id;
		bool operator <(const EmptySeat &es) const {
			return space == es.space ? pos > es.pos : space < es.space;
		}
	};
	priority_queue<EmptySeat> empty;
	set<int> taken;
	unordered_map<int, int> sid;
	int nxtid, n;
public:
    ExamRoom(int N) {
		n = N;
		taken.insert(-1);
		taken.insert(n);
		sid[0] = 0;
		nxtid = 1;
		empty.push(EmptySeat(n-1, 0, 0));
    }
    
    int seat() {
		int pick;
		while (true) {
			auto cur = empty.top();
			empty.pop();
			auto it = sid.find(cur.pos);
			if (it!=sid.end() && it->second==cur.id) {
				pick = cur.pos;
				break;
			}
		}

		auto it = taken.insert(pick).first;
		auto pit = prev(it), nit = next(it);
		if (*pit == -1) {
			if (pick != 0) {
				sid[0] = nxtid;
				empty.push(EmptySeat(pick-1, 0, nxtid++));
			}
		} else {
			if (pick-1 > *pit) {
				int pos = (*pit + pick) / 2;
				sid[pos] = nxtid;
				empty.push(EmptySeat(pos-*pit-1, pos, nxtid++));
			}
		}
		if (*nit == n) {
			if (pick != n-1) {
				sid[n-1] = nxtid;
				empty.push(EmptySeat(n-1-pick-1, n-1, nxtid++));
			}
		} else {
			if (pick+1 < *nit) {
				int pos = (pick + *nit) / 2;
				sid[pos] = nxtid;
				empty.push(EmptySeat(pos-pick-1, pos, nxtid++));
			}
		}
		return pick;
    }
    
    void leave(int p) {
		auto it = taken.find(p);
		auto pit = prev(it), nit = next(it);
		if (*pit == -1) {
			if (p != 0) {
				sid.erase(0);
			}
		} else {
			if (p-1 > *pit) {
				int pos = (*pit + p) / 2;
				sid.erase(pos);
			}
		}
		if (*nit == n) {
			if (p != n-1) {
				sid.erase(n-1);
			}
		} else {
			if (p+1 < *nit) {
				int pos = (p + *nit) / 2;
				sid.erase(pos);
			}
		}

		taken.erase(it);
		int pos, space;
		if (*pit == -1) {
			pos = 0;
			space = *nit-1;
		} else if (*nit == n) {
			pos = n-1;
			space = pos-*pit-1;
		} else {
			pos = (*nit+*pit) / 2;
			space = pos - *pit - 1;
		}
		sid[pos] = nxtid;
		empty.push(EmptySeat(space, pos, nxtid++));
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

int main() {
	int n; cin >> n;
	ExamRoom room(n);
	string cmd;
	while (cin >> cmd) {
		if (cmd == "s") {
			cout << room.seat() << endl;
		} else {
			int p; cin >> p;
			room.leave(p);
		}
	}
	return 0;
}

//--------------
class ExamRoom {
	set<int> taken;
	int n;
public:
    ExamRoom(int N) {
		n = N;
    }
    
    int seat() {
		int ans;
		if (taken.empty()) {
			ans = 0;
		} else {
			int last = 0, mx = *taken.begin(), pick = 0;
			for (auto t: taken) {
				int p = (t+last) / 2;
				int d = p - last;
				if (d > mx) {
					pick = p;
					mx = d;
				}
				last = t;
			}
			if (last < n-1) {
				int d = n-1 - last;
				if (d > mx) {
					mx = d;
					pick = n-1;
				}
			}
			ans = pick;
		}
		taken.insert(ans);
		return ans;
    }
    
    void leave(int p) {
		taken.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
