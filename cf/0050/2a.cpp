#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;

#define MAXN 1000
int scores[MAXN], nscores[MAXN];
int record[MAXN][2];

int main() {
	int n; cin >> n;
	unordered_map<string, int> namemap;
	unordered_map<int, string> idmap;

	int score, id = 0;
	string buff;

	memset(scores, 0, sizeof(scores));
	for (int i=0; i<n; ++i) {
		cin >> buff >> record[i][0];
		auto it = namemap.find(buff);
		if (it == namemap.end()) {
			it = namemap.insert({ buff, id }).first;
			idmap[id++] = move(buff);
		}

		record[i][1] = it->second;
		scores[it->second] += record[i][0];
	}

	int mx = 0xffffffff;
	for (int i=0; i<id; ++i) { mx = max(mx, scores[i]); }

	memset(nscores, 0, sizeof(nscores));
	for (int i=0; i<n; ++i) {
		nscores[record[i][1]] += record[i][0];
		if (nscores[record[i][1]] >= mx && scores[record[i][1]] == mx) {
			cout << idmap[record[i][1]] << endl;
			break;
		}
	}

	return 0;
}
