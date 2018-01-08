/*
 * Special binary: # of 1 == # of 0, all prefixes have # of 1 >= # of 0.
 * Some observation:
 * 1. Concatenation of special binaries is still special binary.
 * 	be cause it will have same number of 1 and 0, and all prefixes have more 1 than 0.
 * 2. Special binary can contain special binaries.
 * 	like: 1100 has 10, 110100 has 1010
 * 3. Special binary can be seen as multiple special binaries, with 0 or more 1s in between
 * special binaries, and necessary 1s in front and 0s at the end.
 *  like: 1101101000 = 1+10+1+10+10+00
 *
 * For the problem a stack can be used to detect specials:
 * if it's a 1, then push its index into the stack
 * else pop the stack, the popped index is the start, the current idx is the end.
 *
 * When a new special is found, it means its internal specials are all found.
 * when found the internal ones, we sort the concecutive ones with insertion sort.
 * So that the containing one is guarenteed to be optimal.
 */
class Solution {
public:
	bool smaller(string &s, int s1, int e1, int s2, int e2) {
		for (int i1 = s1, i2 = s2; i1 <= e1 && i2 <= e2; ++i1, ++i2) {
			if (s[i1] != s[i2]) { return s[i1] < s[i2]; }
		}

		return (e1-s1) < (e2-s2);
	}

	string makeLargestSpecial(string s) {
		stack<int> stk;
		int len = s.length();
		vector<pair<int, int>> rngs(len);
		string buff(len, '0');
		int rcnt = 0;
		for (int i=0; i<len; ++i) {
			if (s[i] == '1') {
				stk.push(i);
			} else {
				int st = stk.top(); stk.pop();
				int ed = i;
				// Erase the internal ones, because they're already processed and the current one
				// is optimal
				while (rcnt > 0 && st < rngs[rcnt-1].first) { --rcnt; }
				rngs[rcnt++] = make_pair(st, ed);
				// insertion sort, reorder with the consecutive ones
				for (int i=rcnt-2; i>=0 && rngs[i+1].first == rngs[i].second+1; --i) {
					if (smaller(s, rngs[i].first, rngs[i].second, rngs[i+1].first, rngs[i+1].second)) {
						// reorder the string and special's start and end
						int slen1 = rngs[i].second - rngs[i].first + 1;
						for (int j=0; j<slen1; ++j) { buff[j] = s[rngs[i].first+j]; }
						int slen2 = rngs[i+1].second - rngs[i+1].first + 1;
						for (int j=0; j<slen2; ++j) { s[rngs[i].first+j] = s[rngs[i+1].first+j]; }
						for (int j=0; j<slen1; ++j) { s[rngs[i].first+slen2+j] = buff[j]; }
						rngs[i].second = rngs[i].first + slen2 - 1;
						rngs[i+1].first = rngs[i].second + 1;
					} else {
						break;
					}
				}
			}
		}

		return s;
	}
};
