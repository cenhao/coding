class LogSystem {
	unordered_map<string, int64_t> mm; //mod map
	map<int64_t, int> idm; // id map
	int64_t read_ts(const string &s, int64_t stop) {
		int64_t ret = 0LL, cur = 0LL, base = 10000000000LL;
		for (int i=0; i<=s.length() && base>=stop; ++i) {
			if (i==s.length() || s[i]==':') {
				ret += cur * base;
				base /= 100;
				cur = 0;
			} else {
				cur = cur * 10 + s[i]-'0';
			}
		}
		return ret;
	}
public:
    LogSystem() {
		mm = {
			{ "Year", 10000000000LL }, { "Month", 100000000LL }, { "Day", 1000000LL },
			{ "Hour", 10000LL }, { "Minute", 100LL }, { "Second", 1LL }
		};
    }
    
    void put(int id, string timestamp) {
		int64_t ts = read_ts(timestamp, 1LL);
		idm[ts] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
		int64_t stop = mm[gra];
		int64_t sts = read_ts(s, stop);
		int64_t ets = read_ts(e, stop) + stop;
		vector<int> ans;
		for (auto it=idm.lower_bound(sts); it!=idm.end() && it->first<ets; ++it) {
			ans.push_back(it->second);
		}
		return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
