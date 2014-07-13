#include <stdio.h>
#include <string.h>

#define CHILD_NUM 26
#define N (10 * 100000)

struct TrieNode {
	int child_ptr[CHILD_NUM];
	int cnt;
}node[N];
int first = 0;

int main() {
	int n, m;
	char word[16];

	while (EOF != scanf("%d", &n)) {
		node[0].cnt = 0;
		memset(node[0].child_ptr, -1, sizeof(node[0].child_ptr));
		first = 1;

		for (int i=0; i<n; ++i) {
			scanf("%s", word);
			size_t len = strlen(word);
			int cur = 0;
			++node[0].cnt;
			for (size_t j=0; j<len; ++j) {
				int idx = word[j] - 'a';
				if (node[cur].child_ptr[idx] < 0) {
					node[cur].child_ptr[idx] = first;
					node[first].cnt = 0;
					memset(node[first].child_ptr, -1,
							sizeof(node[first].child_ptr));
					++first;
				}
				cur = node[cur].child_ptr[idx];
				++node[cur].cnt;
			}
		}

		scanf("%d", &m);
		for (int i=0; i<m; ++i) {
			scanf("%s", word);
			size_t len = strlen(word);
			int cur = 0;
			int ret = 0;

			for (size_t j=0; j<len; ++j) {
				int idx = word[j] - 'a';
				if (node[cur].child_ptr[idx] < 0) {
					ret = 0;
					break;
				} else {
					cur = node[cur].child_ptr[idx];
					ret = node[cur].cnt;
				}
			}

			printf("%d\n", ret);
		}
	}

	return 0;
}
