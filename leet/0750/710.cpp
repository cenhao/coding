class Solution {
	map<int, int> nxt;
	int rsz;
public:
    Solution(int N, vector<int> blacklist) {
		rsz = N - blacklist.size();
		sort(blacklist.begin(), blacklist.end());
		blacklist.push_back(N);
		for (int i=0, pre=-1, cnt=0, sz=blacklist.size(); i<sz; pre=blacklist[i++], ++cnt) {
			if (pre+1 == blacklist[i]) { continue; }
			nxt[pre+1-cnt] = pre+1;
		}
    }
    
    int pick() {
		int r = rand() % rsz;
		auto it = prev(nxt.upper_bound(r));
		return it->second + r - it->first;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
