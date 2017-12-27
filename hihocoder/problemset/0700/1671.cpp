#include <bits/stdc++.h>
using namespace std;

#define MAXS 5000000
char in[MAXS+5], out[MAXS+5];
unordered_map<int, int> hm;

int build(bool flip, int cur, int &nxt) {
	int dir, st, ed;
	if (flip) {
		dir = -1;
		st = max(hm[cur], cur);
		ed = min(hm[cur], cur);
	} else {
		dir = 1;
		st = min(hm[cur], cur);
		ed = max(hm[cur], cur);
	}

	for (int i=st+dir; i!=ed; i+=dir) {
		if (in[i] == '(' || in[i] == ')') {
			i = i + build(!flip, i, nxt)*dir - dir;
		} else {
			out[nxt++] = in[i];
		}
	}

	return abs(ed-st) + 1;
}

int main() {
	in[0] = '(';
	scanf("%s", &in[1]);
	int len = strlen(in);
	in[len] = ')'; in[++len] = 0;

	stack<int> st;
	for (int i=0; i<len; ++i) {
		if (in[i] == '(') {
			st.push(i);
		} else if (in[i] == ')') {
			int sp = st.top(); st.pop();
			hm[i] = sp; hm[sp] = i;
		}
	}

	int nxt = 0;
	build(false, 0, nxt);
	out[nxt] = 0;
	printf("%s\n", out);
	return 0;
}
