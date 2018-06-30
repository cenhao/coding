class Solution {
public:
    vector<int> arrangeSeat(int n, vector<int> &arr) {
		set<int> seats;
		vector<int> ans;
		map<int, int> hm;
		for (auto p: arr) {
			if (p >= 0) {
				int pick = -1;
				if (seats.empty()) {
					pick = 0;
				} else if (seats.size() != n) {
					int dist = -1;
					for (auto it=seats.begin(); it!=seats.end(); ++it) {
						if (it == seats.begin()) {
							if (*it != 0) {
								int tmp = *it-1;
								if (dist==-1 || tmp>dist) {
									dist = tmp; pick = 0;
								}
							}
						} else {
							auto pit = prev(it);
							if (*pit+1 < *it) {
								int mid = (*pit + *it) / 2;
								int tmp = mid-*pit-1;
								if (dist==-1 || tmp>dist) {
									dist = tmp; pick = mid;
								}
							}
						}

						if (next(it)==seats.end() && *it!=n-1) {
							int tmp = n-1-*it-1;
							if (dist==-1 || tmp>dist) {
								dist = tmp; pick = n-1;
							}
						}
					}
				}
				ans.push_back(pick);
				if (pick != -1) { seats.insert(pick); hm[p] = pick; }
			} else {
				auto it = hm.find(-p);
				if (it == hm.end()) {
					ans.push_back(-1);
				} else {
					ans.push_back(1);
					seats.erase(it->second);
					hm.erase(it);
				}
			}
		}

		return ans;
    }
};
