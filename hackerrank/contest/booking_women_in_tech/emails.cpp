#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, queue<string>, greater<int>> storage;
	int n, urg; cin >> n;
	string command, content;
	for (int i=0; i<n; ++i) {
		cin >> command;
		if (command[0] == 's') {
			cin >> content >> urg;
			auto iter = storage.find(urg);
			if (iter == storage.end()) {
				iter = storage.insert(pair<int, queue<string>>(urg, queue<string>())).first;
			}

			iter->second.push(move(content));
		} else {
			if (storage.size() > 0) {
				auto iter = storage.begin();
				cout << iter->second.front() << endl;
				iter->second.pop();
				if (iter->second.size() == 0) {
					storage.erase(iter);
				}
			} else {
				cout << -1 << endl;
			}
		}
	}

	return 0;
}
