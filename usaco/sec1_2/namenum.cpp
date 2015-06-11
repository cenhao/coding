/*
ID: cenhao11
PROG: namenum
LANG: C++
*/

#include <map>
#include <set>
#include <string>
using namespace std;

#include <string.h>
#include <stdint.h>
#include <stdio.h>

const int char2num[] = {2, 2, 2, 3, 3, 3,
	4, 4, 4, 5, 5, 5, 6, 6, 6,
	7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
map<int64_t, set<string> > names;

int init(const char *dictFile)
{
	int cnt = 0;
	char name[20] = {0, };
	FILE* fdict = fopen(dictFile, "r");

	while (EOF != fscanf(fdict, "%s\n", name)) {
		++cnt;
		string sname(name);
		size_t len = strlen(name);
		int64_t sum = int64_t(0);

		for (size_t i=0; i<len; ++i) {
			sum *= int64_t(10);
			sum += int64_t(char2num[name[i]-'A']);
		}

		map<int64_t, set<string> >::iterator iter = names.find(sum);

		if (iter == names.end()) {
			set<string> nameset;
			nameset.insert(name);
			names.insert(pair<int64_t, set<string> >(sum, nameset));
		} else {
			iter->second.insert(name);
		}
	}

	return cnt;
}

int main()
{
	init("dict.txt");
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);

	int64_t id;
	char szId[15] = {0, };
	map<int64_t, set<string> >::iterator iter;

	while (EOF != scanf("%s\n", szId)) {
		id = int64_t(0);
		size_t len = strlen(szId);

		for (size_t i=0; i<len; ++i) {
			id *= int64_t(10);
			id += int64_t(szId[i] - '0');
		}

		iter = names.find(id);
		if (iter == names.end()) { printf("NONE\n"); }
		else{
			for (set<string>::iterator i=iter->second.begin(); i!=iter->second.end(); ++i) {
				printf("%s\n", (*i).c_str());
			}
		}
	}

	return 0;
}
