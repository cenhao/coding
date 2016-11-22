/*
 * The modeling of the problem is the most important key of solving it:
 * Even B borrowed money from A, doesn't mean that he has to return money to A,
 * as long as B is even in his account at the end - he does not lose or gain
 * any money. For instance, if B borrowed $5 from A, and lended $5 to C, then
 * B is even, in this case, he can told C to return the $5 to A, and he doesn't
 * need a transaction from either A or C.
 *
 * Then here comes the next concept: even group. People in this group, adding all
 * the debts from everyone in the group, the group doesn't gain or lose any thing.
 * But there's one condiction: everyone is not even at the beginning.
 * For example: if A owned X $5, B lended Y $3, C lended Y $2, then A, B and C can
 * form a group, and in this group, A returns $3 to B, $2 to C, then everyone in
 * this group is even. X, Y can form another group that Y returns X $5.
 * But if A lended B $1, B lended C $1, C lended A $1, [A, B, C] is not a even group,
 * as everyone is even already.
 *
 * All the people participated in the transactions is already a group, like the
 * [A, B, C, X, Y] mentioned aboved. However, even subgroup could be formed from 
 * a group. Like [A, B, C], [X, Y].
 *
 * Let's call a group which forms no even subgroup a minimum group. To make everyone
 * in a minimum group `G` even requires at least |G|-1 transactions.
 *
 * So the more even subgroup we can find, the fewer transaction we need to make.
 *
 * The way to find even subgroup:
 * 1. Remove the people who are already even.
 * 2. Enumerate all the subset from people who are not even.
 * 	2.1 If the subset is even, the complementary set is also even.
 * 	2.2. We continue to find if the complementary set can be devided into smaller
 * 			even subgroup.
 *
 * As a set can be represented by a bitmap, an array can be used to store the maximum
 * number of even subgroup can be found in a set.
 *
 * Hence at the end, this problem is a state DP.
 */
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int gs[1 << 20]; // group sum
int mxg[1 << 20]; // maximum number of groups
class Solution {
	public:
	int minTransfers(vector<vector<int>>& transactions) {
		unordered_map<int, int> mdebt;
		for (auto &t : transactions) {
			mdebt[t[0]] -= t[2]; mdebt[t[1]] += t[2];
		}

		vector<int> vdebt;
		for (auto &ent : mdebt) {
			if (ent.second) { vdebt.push_back(ent.second); }
		}

		gs[0] = 0;
		int n = vdebt.size();
		for (int i=1, end=1<<n; i<end; ++i) {
			int idx = firstbit(i);
			gs[i] = vdebt[idx] + gs[i^(1<<idx)];
		}

		for (int i=0, end=1<<n; i<end; ++i) {
			mxg[i] = 0;
			if (gs[i] != 0) { continue; }
			for (int sub=i; sub>0; sub=(sub-1)&i) {
				if (gs[i^sub] != 0) { continue; }
				mxg[i] = max(mxg[i], mxg[i^sub]+1);
			}
		}

		return n - mxg[(1<<n)-1];
	}

	int firstbit(int n) {
		int pos;
		for (pos = 0; (n & (1<<pos)) == 0; ++pos);
		return pos;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> in;
	for (int i=0; i<n; ++i) {
		vector<int> t(3);
		cin >> t[0] >> t[1] >> t[2];
		in.push_back(move(t));
	}

	Solution sol;
	cout << sol.minTransfers(in) << endl;
	return 0;
}
