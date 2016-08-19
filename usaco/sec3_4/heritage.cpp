/*
ID: cenhao11
PROG: heritage
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

char in[28];
char pre[28];
int node[28][2];

void print(int cur) {
	if (node[cur][0] >= 0) {
		print(node[cur][0]);
	}
	if (node[cur][1] >= 0) {
		print(node[cur][1]);
	}
	if (cur <= 26) { printf("%c", cur+'A'); }
}

void process() {
	memset(node, -1, sizeof(node));
	int root = 27;

	for (int lv=0; pre[lv]!=0; ++lv) {
		int cur = root;

		while (true) {
			bool left = false;
			for (int lv2=0; in[lv2]!=0 && in[lv2]!=cur+'A'; ++lv2) {
				if (in[lv2] == pre[lv]) {
					left = true;
					break;
				}
			}

			int idx = left ? 0 : 1;
			if (node[cur][idx] < 0) {
				node[cur][idx] = pre[lv] - 'A';
				break;
			}

			cur = node[cur][idx];
		}
	}

	print(root);
	printf("\n");
}

int main() {
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);

	scanf("%s", in);
	scanf("%s", pre);
	process();
	return 0;
}
