#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define MAXS 60

char in[MAXN][MAXS+1];
int idx[MAXN];
char key[MAXN][MAXS+1];

void getkey(int n, int k) {
	for (int i=0; i<n; ++i) {
		int len = strlen(in[i]);
		for (int j=0, cnt=0, pos=0; j<=len && cnt<k; ++j) {
			if (j==len || in[i][j] == ' ') {
				++cnt;
				key[i][pos] = 0;
				pos = 0;
			} else {
				key[i][pos++] = in[i][j];
			}
		}
	}
}

bool ncmp(int a, int b) {
	int la = strlen(key[a]), lb = strlen(key[b]);
	int pa = 0; while (pa<la-1 && key[a][pa] == '0') { ++pa; }
	int pb = 0; while (pb<lb-1 && key[b][pb] == '0') { ++pb; }

	if (la - pa != lb - pb) { return la - pa < lb - pb; }
	while (pa < la) {
		if (key[a][pa] != key[b][pb]) {
			return key[a][pa] < key[b][pb];
		}
		++pa; ++pb;
	}

	return a < b;
}

int main() {
	fgets(in[0], MAXS, stdin);
	int n; sscanf(in[0], "%d", &n);
	for (int i=0; i<n; ++i) {
		fgets(in[i], MAXS, stdin);
		int len = strlen(in[i]);
		if (in[i][len-1] == '\n') { in[i][len-1] = 0; }
		idx[i] = i;
	}
	
	int k;
	char rev[MAXS], type[MAXS];
	scanf("%d%s%s", &k, rev, type);

	bool r = rev[0] == 't';
	bool is_numeric = type[0] == 'n';

	getkey(n, k);

	sort(idx, idx+n, [&](int i1, int i2) {
		bool ret;
		if (is_numeric) {
			ret = ncmp(i1, i2);
		}
		else {
			int v = strcmp(key[i1], key[i2]);
			ret = (v == 0) ? i1 < i2 : v < 0;
		}

		return r ? !ret : ret;
	});

	for (int i=0; i<n; ++i) { printf("%s\n", in[idx[i]]); }
	return 0;
}
