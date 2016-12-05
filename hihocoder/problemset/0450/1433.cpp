#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

#define MAXL 10

int main() {
	char src[MAXL+1], dst[MAXL+1];
	unordered_map<string, int> diff;

	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s %s", src, dst);
		string ssrc = string(src);
		string sdst = string(dst);
		auto it = diff.find(ssrc);
		if (it == diff.end()) {
			it = diff.insert(pair<string, int>(move(ssrc), 0)).first;
		}
		++(it->second);
		it = diff.find(sdst);
		if (it == diff.end()) {
			it = diff.insert(pair<string, int>(move(sdst), 0)).first;
		}
		--(it->second);
	}

	string s, d;
	for (auto &entry : diff) {
		if (entry.second > 0) {
			s = entry.first;
		} else if (entry.second < 0) {
			d = entry.first;
		}
	}

	printf("%s %s\n", s.c_str(), d.c_str());
	return 0;
}
