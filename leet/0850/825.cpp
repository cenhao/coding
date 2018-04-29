class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121, 0); 
        int ans = 0;
        for (auto a: ages) { ++cnt[a]; }
        for (int i=1; i<=120; ++i) {
            if (cnt[i] <= 0) { continue; }

            int mn = (i / 2) + 7 + 1;
            for (int j=mn; j<=i; ++j) {
				if (i == j) {
					ans += cnt[i] * (cnt[j]-1);
				} else {
					ans += cnt[i] * cnt[j];
				}
			}
        }   
        return ans;
    }   
};
