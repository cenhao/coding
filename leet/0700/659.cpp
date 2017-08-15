/*
 * The key to the problem is to understand that,
 * try to match the sequence that's not long enough yet.
 */
class Solution {
public:
	bool isPossible(vector<int>& nums) {
		int pos = 0, sz = nums.size();
		int first = 1, last, cnt[2][3], cur = 0, pre = 1;
		memset(cnt, 0, sizeof(cnt));
		while (pos < sz) {
			int cv = nums[pos], ccnt = 0;
			while (pos < sz && nums[pos] == cv) {
				++pos;
				++ccnt;
			}
			
			cnt[cur][0] = cnt[cur][1] = cnt[cur][2] = 0;
			if (first == 0 && cv == last+1) {
				for (int j=0; j<3; ++j) {
					int take = min(ccnt, cnt[pre][j]);
					ccnt -= take; cnt[pre][j] -= take;
					cnt[cur][min(2, j+1)] += take;
				}
			}
			cnt[cur][0] = ccnt;
			if (cnt[pre][0] > 0 || cnt[pre][1] > 0) { return false; }
			pre = cur; cur = (cur + 1) % 2;
			first = 0;
			last = cv;
		}
		return cnt[pre][0] == 0 && cnt[pre][1] == 0;
	}
};
