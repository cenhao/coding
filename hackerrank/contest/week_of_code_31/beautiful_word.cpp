#include <bits/stdc++.h>
using namespace std;

#define MAXW 100
char word[MAXW+1];

int main() {
	scanf("%s", word);
	int len = strlen(word);

	char pre = 0;
	bool beautiful = true;
	for (int i=0; i<len; ++i) {
		if (word[i] == 'a' || word[i] == 'e' ||
			word[i] == 'i' || word[i] == 'o' ||
			word[i] == 'u' || word[i] == 'y') {
			word[i] = 'a';
		}

		if (word[i] == pre) {
			beautiful = false;
			break;
		}

		pre = word[i];
	}

	printf(beautiful ? "Yes\n" : "No\n");
	return 0;
}
