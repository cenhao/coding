class Solution {
public:
	void gen(int cur, int len, vector<int> &p, string &buf, vector<int> &pp) {
		if (cur >= (len+1)/2) {
			int v = stoi(buf);
			if (v == 1) { return; }
			int stop = sqrt(v);
			bool ok = true;
			for (auto pv: p) {
				if (pv > stop) { break; }
				if (v % pv == 0) {
					ok = false;
					break;
				}
			}
			if (ok) { pp.push_back(v); }
			return;
		}
		for (int i=cur==0?'1':'0'; i<='9'; ++i) {
			buf[cur] = buf[len-cur-1] = i;
			gen(cur+1, len, p, buf, pp);
		}
	}
	int primePalindrome(int N) {
		static bool init = false;
		static vector<int> pp;
		if (!init) {
			init = true;
			int sz = 10100;
			vector<bool> is_prime(sz, true);
			vector<int> p;
			for (int i=2; i<sz; ++i) {
				if (is_prime[i]) { p.push_back(i); }
				for (int j=0; j<p.size() && i*p[j]/p[j]==i && i*p[j]<sz; ++j) {
					is_prime[i*p[j]] = false;
					if (i % p[j] == 0) { break; }
				}
			}

			for (int i=1; i<=7; ++i) {
				string buf(i, ' ');
				gen(0, i, p, buf, pp);
			}
			pp.push_back(100030001);
			sort(pp.begin(), pp.end());
		}

		auto it = lower_bound(pp.begin(), pp.end(), N);
		return *it;
	}
};
