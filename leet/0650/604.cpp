#include <bits/stdc++.h>
using namespace std;
class StringIterator {
public:
	int cnt;
	char cur;
	int nxt;
	string str;
	StringIterator(string compressedString) {
		if (compressedString.length() == 0) {
			cnt = 0;
			cur = 0;
			nxt = 0;
		} else {
			str = move(compressedString);
			cnt = 0;
			nxt = 0;
		}
	}

	char next() {
		if (nxt >= str.length() && cnt <= 0) { return ' '; }
		if (cnt > 0) {
			--cnt;
			return cur;
		}
		cur = str[nxt++];
		cnt = 0;

		while (nxt < str.length() &&
			   str[nxt] >= '0' && str[nxt] <= '9') {
			cnt = cnt * 10 + str[nxt++] - '0';
		}

		--cnt;
		return cur;
	}

	bool hasNext() {
		return (cnt > 0 || nxt < str.length());
	}
};

int main() {
	StringIterator iterator("L1e2t1C1o1d1e1");

	cout << iterator.next(); // return 'L'
	cout << iterator.next(); // return 'e'
	cout << iterator.next(); // return 'e'
	cout << iterator.next(); // return 't'
	cout << iterator.next(); // return 'C'
	cout << iterator.next(); // return 'o'
	cout << iterator.next(); // return 'd'
	cout << iterator.hasNext(); // return true
	cout << iterator.next(); // return 'e'
	cout << iterator.hasNext(); // return false
	cout << iterator.next(); // return ' '
	string s; cin >> s;
	StringIterator si(s);
	cout << si.next() << endl;
	return 0;
}
