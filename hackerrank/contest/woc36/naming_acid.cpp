#include <bits/stdc++.h>
using namespace std;

string acidNaming(string acid_name) {
	int len = acid_name.length();
	if (acid_name[len-2] == 'i' && acid_name[len-1] == 'c') {
		if (acid_name.substr(0, 5) == "hydro") {
			return "non-metal acid";
		} else {
			return "polyatomic acid";
		}
	}

	return "not an acid";
}

int main() {
    int n; cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string acid_name; cin >> acid_name;
        string result = acidNaming(acid_name);
        cout << result << endl;
    }
    return 0;
}
