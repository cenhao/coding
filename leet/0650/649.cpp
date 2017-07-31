class Solution {
public:
	string predictPartyVictory(string senate) {
		queue<char> q;
		int rcnt = 0, dcnt = 0;
		for (int i=0, end=senate.length(); i<end; ++i) {
			q.push(senate[i]);
			if (senate[i] == 'R') {
				++rcnt;
			} else {
				++dcnt;
			}
		}

		int rbuff = 0, dbuff = 0;
		while (!q.empty() && rcnt > 0 && dcnt > 0) {
			char cur = q.front(); q.pop();
			if (cur == 'R') {
				if (dbuff > 0) {
					--dbuff;
				} else {
					++rbuff;
					--dcnt;
					q.push(cur);
				}
			} else {
				if (rbuff > 0) {
					--rbuff;
				} else {
					++dbuff;
					--rcnt;
					q.push(cur);
				}
			}
		}

		return (rcnt > dcnt) ? "Radiant" : "Dire";
	}
};
