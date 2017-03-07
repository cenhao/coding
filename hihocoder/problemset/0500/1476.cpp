#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000
#define MAXK 10

struct Block {
	int x, y;
} blocks[10];

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<k; ++i) { scanf("%d %d", &blocks[i].x, &blocks[i].y); }
	sort(blocks, blocks+k, [](const Block &b1, const Block &b2) {
		return b1.x == b2.x ? (b1.y > b2.y) : (b1.x > b2.x);
	});

	int64_t sum = 0;
	for (int i=1; i<=n; ++i) {
		for (int i1=1; i1<=m; ++i1) {
			int last=i, yblock=0;
			for (int i2=0; i2<k; ++i2) {
				if (blocks[i2].x > i || blocks[i2].y > i1) { continue; }

				if (blocks[i2].y > yblock) {
					sum += (last-blocks[i2].x) * (i1-yblock);
					yblock = blocks[i2].y;
					last = blocks[i2].x;
				}

			}

			sum += last * (i1-yblock);
		}
	}

	printf("%" PRId64 "\n", sum);
	return 0;
}
