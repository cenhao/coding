#include <bits/stdc++.h>
using namespace std;

int main() {
	string line; getline(cin, line);
	int l; cin >> l;
	string landmarks[100];
	for (int i=0; i<l; ++i) { cin >> landmarks[i]; }
	line += '\n';

	string ans, buff;
	for (int i=0; i<line.length(); ++i) {
		if (line[i] < 'a' || line[i] > 'z') {
			if (buff.length() > 0) {
				bool highlight = false;
				for (int j=0; j<l; ++j) {
					if (buff == landmarks[j]) {
						highlight = true;
						break;
					}
				}

				if (highlight) {
					ans += "<b>" + move(buff) + "</b>";
				} else {
					ans += move(buff);
				}

				buff = "";
			}

			ans += line[i];
		} else {
			buff += line[i];
		}
	}

	cout << ans;
	return 0;
}
