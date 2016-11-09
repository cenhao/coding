#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

class Solution {
	public:
		string minWindow(string s, string t) {
			int cnt[256]; memset(cnt, 0, sizeof(cnt));

			int need[256]; memset(need, 0, sizeof(need));
			for (auto c: t) { ++need[c]; }
			
			int start = 0, end, stop;
			int target = t.length(), meet = 0;
			int mn = 0x7ffffff0, st = 0, ed = -1;
			for (end=0, stop=s.length(); end<stop; ++end) {
				if (!need[s[end]]) { continue; }
				if (++cnt[s[end]] <= need[s[end]]) { ++meet; }
				while (need[s[start]]==0 || cnt[s[start]]>need[s[start]]) {
					--cnt[s[start]];
					++start;
				}

				if (meet >= target) {
					if ((end-start+1) < mn) {
						st = start; ed = end;
						mn = end-start+1;
					}
				}
			}

			return s.substr(st, ed-st+1);
		}
};
