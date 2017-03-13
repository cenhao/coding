#include <cstdio>
using namespace std;

int main() {
	int r, c; scanf("%d %d", &r, &c);
	for (int i=0; i<r; ++i) {
		for (int i=0; i<c; ++i) { printf("..O.."); }
		printf("\n");
		for (int i=0; i<c; ++i) { printf("O.o.O"); }
		printf("\n");
		for (int i=0; i<c; ++i) { printf("..O.."); }
		printf("\n");
	}

	return 0;
}
