#include <stdio.h>
#include <string.h>

#define MAXN 20000
#define MAXS 255
#define INF 0x7fff0000

char buff[MAXS+1];
char time[10];
char state[10];
int cur;

struct Func {
	char name[MAXS+1];
	int parent, nxt;
	int sc, ec;
	int st, et;
} f[MAXN];
int first = 0;

int getTime(char *time) {
	time[2] = time [5] = 0;
	int h, m, s;
	sscanf(time, "%d", &h);
	sscanf(&time[3], "%d", &m);
	sscanf(&time[6], "%d", &s);
	return h * 3600 + m * 60 + s;
}

bool process() {
	int ts = getTime(time);

	if (strncmp("START", state, 10) == 0) {
		int child = ++first;
		f[child].parent = cur;
		f[child].sc = f[child].ec = f[child].nxt = -1;
		f[child].st = ts; f[child].et = -1;
		strncpy(f[child].name, buff, MAXS+1);

		if (f[cur].ec == -1) {
			f[cur].sc = f[cur].ec = child;
		} else {
			f[f[cur].ec].nxt = child;
			f[cur].ec = child;
		}

		cur = child;
	} else {
		if (strncmp(buff, f[cur].name, MAXS) != 0) { return true; }
		f[cur].et = ts;
		cur = f[cur].parent;
	}

	return false;
}

bool check(int start) {
	int lastEnd = -1;
	for (int i=f[start].sc; i!=-1; i=f[i].nxt) {
		if (f[i].st < lastEnd || f[i].et < f[i].st) { return true; }
		lastEnd = f[i].et;
		if (check(i)) { return true; }
	}

	return false;
}

void print(int start) {
	if (start != 0) {
		int d = f[start].et - f[start].st;
		printf("%s %02d:%02d:%02d\n", f[start].name, d/3600, (d%3600)/60, (d%60));
	}
	for (int i=f[start].sc; i!=-1; i=f[i].nxt) {
		print(i);
	}
}

int main() {
	int n; scanf("%d", &n);
	bool invalid = false;
	f[0].name[0] = 0;
	f[0].sc = f[0].ec = -1;
	f[0].st = -1; f[0].et = INF;

	for (int i=0; i<n; ++i) {
		scanf("%s %s %s", buff, time, state);
		if (invalid) { continue; }
		invalid = process();
	}

	if (!invalid) { invalid = check(0); }

	if (invalid) {
		printf("Incorrect performance log\n");
	} else {
		print(0);
	}

	return 0;
}
