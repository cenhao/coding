#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_map<string, int> wmap;
		for (auto &w : wordList) { wmap.insert({ w, 0 }); }
		if (wmap.find(endWord) == wmap.end()) { return 0; }
		wmap[beginWord] = 1;
		wmap[endWord] = -1;

		queue<string> fq, bq;
		fq.push(beginWord);
		bq.push(endWord);

		int ans = 0;
		while (!fq.empty() && !bq.empty() && ans==0) {
			queue<string> *qp, tmp;
			int inc;
			if (fq.size() > bq.size()) {
				qp = &bq; inc = -1;
			} else {
				qp = &fq; inc = 1;
			}
			while (!qp->empty() && ans==0) {
				string cur = move(qp->front()); qp->pop();
				int v = wmap[cur];
				for (int i=0; i<cur.length() && ans==0; ++i) {
					char c = cur[i];
					for (int j='a'; j<='z'; ++j) {
						if (j == c) { continue; }
						cur[i] = j;
						unordered_map<string, int>::iterator it;
						if (wmap.end() == (it=wmap.find(cur))) { continue; }
						if (it->second == 0) {
							it->second = v + inc;
							tmp.push(cur);
						} else if (it->second*v < 0) {
							ans = abs(it->second) + abs(v);
							break;
						}
					}
					cur[i] = c;
				}
			}

			*qp = move(tmp);
		}

		return ans;
	}
};
