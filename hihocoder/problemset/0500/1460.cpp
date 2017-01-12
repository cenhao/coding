#include <cstdio>
#include <cstring>
using namespace std;

#define MAXS 100000

char in[MAXS+1];

int main() {
	int k; scanf("%d %s", &k, in);

	for (int i=0, pos=0, end=strlen(in); i<end; ++i) {
		int left = end - i - 1;
		while (pos>0 && in[i]<in[pos-1] && pos+left>=k) { --pos; }
		in[pos++] = in[i];
	}

	in[k] = 0;
	printf("%s\n", in);
	return 0;
}
