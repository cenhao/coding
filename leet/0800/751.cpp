class Solution {
public:
	string build(int64_t n, int cnt) {
		string ret = "";
		for (int i=3; i>=0; --i) {
			int64_t v = (n >> (i*8)) & 0xffLL;
			if (i != 3) { ret += '.'; }
			ret += to_string(v);
		}

		ret += '/';
		ret += to_string(32-cnt);
		return ret;
	}
	vector<string> ipToCIDR(string ip, int range) {
		int len = ip.length();
		vector<string> sip(4);
		for (int i=0, cur=0; i<len; ++i) {
			if (ip[i] == '.') {
				++cur;
			} else {
				sip[cur] += ip[i];
			}
		}

		unordered_map<int64_t, int> cm;
		for (int i=0; i<32; ++i) {
			int64_t t = 1LL << i;
			cm[t] = i;
		}
		int64_t start = 0;
		for (int i=0; i<4; ++i) { start = (start << 8) + stoi(sip[i]); }
		int64_t end = start + range;
		vector<string> ans;
		while (start < end) {
			int64_t lb = start & (~(start&(start-1)));
			int cnt = cm[lb];
			while (start + (1LL<<cnt) - 1 >= end) {
				--cnt;
			}

			ans.push_back(move(build(start, cnt)));
			start += 1LL << cnt;
		}

		return ans;
	}
};
