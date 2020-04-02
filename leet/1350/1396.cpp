class UndergroundSystem {
public:
	unordered_map<int, pair<string, int>> in;
	unordered_map<string, unordered_map<string, pair<int, int>>> cnt;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
		in[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
		auto it = in.find(id);
		auto cit = cnt.find(it->second.first);
		if (cit == cnt.end()) {
			cit = cnt.insert(make_pair(it->second.first, unordered_map<string, pair<int, int>>())).first;
		}

		auto oit = cit->second.find(stationName);
		if (oit == cit->second.end()) {
			oit = cit->second.insert(make_pair(stationName, make_pair(0, 0))).first;
		}

		oit->second.first += t - it->second.second;
		oit->second.second += 1;
		in.erase(it);
    }
    
    double getAverageTime(string startStation, string endStation) {
		auto p = cnt[startStation][endStation];
		return p.first * 1.0 / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
