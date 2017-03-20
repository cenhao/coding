#include <bits/stdc++.h>

char buff[7];

bool is_vowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void dfs(int cur, bool was_vowel, int end) {
	if (cur == end) {
		buff[cur] = 0;
		printf("%s\n", buff);
		return;
	}
	for (int i=0; i<26; ++i) {
		if (i == 24) { continue; }
		if (was_vowel == is_vowel('a' + i)) { continue; }
		buff[cur] = 'a' + i;
		dfs(cur+1, !was_vowel, end);
	}
}

int main() {
	int n; scanf("%d", &n);
	dfs(0, false, n);
	dfs(0, true, n);
	return 0;
}
