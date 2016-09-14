#include <stdio.h>
#include <string.h>

#define MAXS 26

char pre[MAXS+1];
char in[MAXS+1];

int build(int cur, int start, int end) {
	if (start >= end) { return 0; }
	int pos;
	for (int i=start; i<end; ++i) {
		if (in[i] == pre[cur]) {
			pos = i;
			break;
		}
	}

	int used = build(cur+1, start, pos);
	used += build(cur+used+1, pos+1, end);
	printf("%c", pre[cur]);
	return used + 1;
}

void process() {
	build(0, 0, strlen(pre));
	printf("\n");
}

int main() {
	scanf("%s %s", pre, in);
	process();
	return 0;
}
