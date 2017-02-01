#include <cstdio>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

#define MAXS 32

int main() {
	int n, m; scanf("%d %d", &n, &m);

	queue<string> time;
	unordered_map<string, int> hashmap;
	char buff[MAXS];

	for (int i=0; i<n; ++i) {
		scanf("%s", buff);
		string url(buff);

		unordered_map<string, int>::iterator it;
		if ((it=hashmap.find(url)) != hashmap.end()) {
			++it->second;
			printf("Cache\n");
		} else {
			printf("Internet\n");
			++hashmap[url];

			while (hashmap.size() > m) {
				it = hashmap.find(time.front());
				time.pop();
				if (--it->second == 0) {
					hashmap.erase(it);
				}
			}
		}

		time.push(move(url));
	}

	return 0;
}
