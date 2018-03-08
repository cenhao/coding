#include <bits/stdc++.h>
using namespace std;

inline int to_int(char c) {
	return (c >= '0' && c <= '9') ?  c - '0' : c-'a'+10;
}

int main() {
	char s[16]; scanf("%s", s);
	int rgb[3];
	for (int i=0; i<3; ++i) {
		rgb[i] = to_int(s[i*2+1]) * 16 + to_int(s[i*2+2]);
		int diff = 0x7fffffff, tmp;
		for (int j=0; j<16; ++j) {
			int v = abs((j<<4)+j - rgb[i]);
			if (v < diff) {
				diff = v;
				tmp = j;
			}
		}
		rgb[i] = tmp;
	}

	printf("#%x%x%x\n", rgb[0], rgb[1], rgb[2]);
	return 0;
}
