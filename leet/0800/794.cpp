#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool validTicTacToe(vector<string>& board) {
		int xcnt = 0, ocnt = 0;
		int xcm[3] = { 0, 0, 0 };
		int ocm[3] = { 0, 0, 0 };
		int xdm = 0, xrdm = 0, odm = 0, ordm = 0;
		bool xwin = false, owin = false;
		for (int i=0; i<3; ++i) {
			int xrm = 0, orm = 0;
			for (int j=0; j<3; ++j) {
				if (board[i][j] == 'X') {
					++xcnt;
					xrm |= (1<<j);
					xcm[j] |= (1<<i);
					if (i == j) { xdm |= 1 << i; }
					if (i+j == 2) { xrdm |= 1<<i; }
				} else if (board[i][j] == 'O') {
					++ocnt;
					orm |= (1<<j);
					ocm[j] |= (1<<i);
					if (i == j) { odm |= 1 << i; }
					if (i+j == 2) { ordm |= 1<<i; }
				}
			}

			xwin |= xrm == 7;
			owin |= orm == 7;
		}
		xwin |= xdm == 7;
		owin |= odm == 7;
		xwin |= xrdm == 7;
		owin |= ordm == 7;
		for (int i=0; i<3; ++i) {
			xwin |= xcm[i] == 7;
			owin |= ocm[i] == 7;
		}

		if (xcnt > ocnt+1 || xcnt < ocnt) { return false; }
		if (xwin && owin) { return false; }
		if (xwin && xcnt != ocnt+1) { return false; }
		if (owin && xcnt != ocnt) { return false; }

		return true;
	}
};

int main() {
	vector<string> b(3);
	for (int i=0; i<3; ++i) cin >> b[i];
	Solution sol;
	cout << sol.validTicTacToe(b) << endl;
	return 0;
}
