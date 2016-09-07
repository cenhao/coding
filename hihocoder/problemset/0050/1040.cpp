#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

struct Segment {
	int64_t x1, y1;
	int64_t x2, y2;
} segs[4];

bool parallel(int sn1, int sn2) {
	int64_t v1x = segs[sn1].x1 - segs[sn1].x2;
	int64_t v1y = segs[sn1].y1 - segs[sn1].y2;
	int64_t v2x = segs[sn2].x1 - segs[sn2].x2;
	int64_t v2y = segs[sn2].y1 - segs[sn2].y2;

	return (v1x * v2y - v2x * v1y) == 0;
}

bool coincident(int sn1, int sn2) {
	int64_t v1x = segs[sn1].x1 - segs[sn1].x2;
	int64_t v1y = segs[sn1].y1 - segs[sn1].y2;
	int64_t v2x = segs[sn2].x1 - segs[sn1].x2;
	int64_t v2y = segs[sn2].y1 - segs[sn1].y2;

	return (v1x * v2y - v1y * v2x) == 0;
}

bool prependicular(int sn1, int sn2) {
	int64_t v1x = segs[sn1].x1 - segs[sn1].x2;
	int64_t v1y = segs[sn1].y1 - segs[sn1].y2;
	int64_t v2x = segs[sn2].x1 - segs[sn2].x2;
	int64_t v2y = segs[sn2].y1 - segs[sn2].y2;

	return (v1x * v2x + v1y * v2y) == 0;
}

bool intersect(int sn1, int sn2) {
	int64_t v1x, v1y, v2x, v2y, z1, z2;

	v1x = segs[sn1].x1 - segs[sn1].x2;
	v1y = segs[sn1].y1 - segs[sn1].y2;

	v2x = segs[sn2].x1 - segs[sn1].x2;
	v2y = segs[sn2].y1 - segs[sn1].y2;
	z1 = (v1x * v2y - v2x * v1y);

	v2x = segs[sn2].x2 - segs[sn1].x2;
	v2y = segs[sn2].y2 - segs[sn1].y2;
	z2 = (v1x * v2y - v2x * v1y);

	if (z1 != 0 && z2 != 0 && ((z1>0 && z2>0) || (z1<0 && z2<0))) { return false; }

	v1x = segs[sn2].x1 - segs[sn2].x2;
	v1y = segs[sn2].y1 - segs[sn2].y2;

	v2x = segs[sn1].x1 - segs[sn2].x2;
	v2y = segs[sn1].y1 - segs[sn2].y2;
	z1 = (v1x * v2y - v2x * v1y);

	v2x = segs[sn1].x2 - segs[sn2].x2;
	v2y = segs[sn1].y2 - segs[sn2].y2;
	z2 = (v1x * v2y - v2x * v1y);

	if (z1 != 0 && z2 != 0 && ((z1>0 && z2>0) || (z1<0 && z2<0))) { return false; }

	return true;
}

bool formedRectangle() {
	int parallelCnt = 0;
	int prependicularCnt = 0;
	int other[3];

	for (int i=1; i<4; ++i) {
		if (parallel(0, i)) {
			++parallelCnt;
			if (coincident(0, i)) {
				return false;
			}

			other[2] = i;
		} else if (prependicular(0, i)) {
			other[prependicularCnt++] = i;
		}
	}

	if (parallelCnt != 1 || prependicularCnt != 2) { return false; }
	if (coincident(other[0], other[1])) { return false; }

	if (!intersect(0, other[0]) || !intersect(0, other[1]) ||
			!intersect(other[2], other[0]) || !intersect(other[2], other[1])) {
		return false;
	}

	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i=0; i<4; ++i) {
			scanf("%"SCNd64" %"SCNd64" %"SCNd64" %"SCNd64"", &segs[i].x1, &segs[i].y1, &segs[i].x2, &segs[i].y2);
		}
		printf("%s\n", formedRectangle() ? "YES" : "NO");
	}
}
