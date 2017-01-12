#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXS 100000

char in[MAXS+1];
int ccnt[26];

int main() {
	int k; scanf("%d %s", &k, in);

	memset(ccnt, 0, sizeof(ccnt));
	int len = strlen(in);
	int mx = 0;

	for (int i=0; i<len; ++i) { ++ccnt[in[i]-'a']; }
	for (int i=0; i<26; ++i) {
		char target = i + 'a';
		for (int h=0, r=0, scnt=0, mcnt=0; h<len; ++h) {
			if (in[h] != target) {
				++scnt;
			} else {
				++mcnt;
			}


			if (scnt > k || scnt > ccnt[i]-mcnt) {
				while (in[r] == target) { ++r; --mcnt; }
				++r; --scnt;
			}

			mx = max(mx, h-r+1);
		}
	}

	printf("%d\n", mx);
}
