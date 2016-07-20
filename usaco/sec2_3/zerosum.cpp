/*
ID: cenhao11
PROG: zerosum
LANG: C++11
*/

#include <stdio.h>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#define MAXN 9

char exp[MAXN * 2];
vector<string> ans;

void prep(int n) {
	for (int i=0; i<n; ++i) {
		exp[i * 2] = '1' + i;
	}

	exp[n * 2 - 1] = 0;
}

void dfs(int start, int end, int sum, char lastOp, int lastVal) {
	if (start+1 == end) {
		lastVal = lastVal * 10 + exp[start] - '0';
		sum += (lastOp == '+' ? 1 : -1) * lastVal;
		if (sum == 0) {
			ans.push_back(string(exp));
		}

		return ;
	}

	if (exp[start] == '+' || exp[start] == '-') {
		sum += (lastOp == '+' ? 1 : -1) * lastVal;
		dfs(start+1, end, sum, exp[start], 0);
	} else if (exp[start] >= '1' && exp[start] <= '9') {
		lastVal = lastVal * 10 + exp[start] - '0';
		exp[start+1] = ' ';
		dfs(start+1, end, sum, lastOp, lastVal);
		exp[start+1] = '+';
		dfs(start+1, end, sum, lastOp, lastVal);
		exp[start+1] = '-';
		dfs(start+1, end, sum, lastOp, lastVal);
	} else {
		dfs(start+1, end, sum, lastOp, lastVal);
	}
}

void dfs(int n) {
	dfs(0, n*2-1, 0, '+', 0);
}

int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);

	int n;
	scanf("%d", &n);
	prep(n);
	dfs(n);
	for (int i=0, len=ans.size(); i<len; ++i) {
		printf("%s\n", ans[i].c_str());
	}

	return 0;
}
