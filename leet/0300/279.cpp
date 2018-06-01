class Solution {
public:
	int numSquares(int n) {
		vector<int> step(n+1, -1);
		step[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty() && step[n]==-1) {
			int cur = q.front();
			q.pop();
			int cs = step[cur];
			for (int i=1; i*i/i==i && cur+i*i<=n; ++i) {
				if (step[cur+i*i] == -1) {
					step[cur+i*i] = cs + 1;
					if (cur+i*i == n) { break; }
					q.push(cur+i*i);
				}
			}
		}

		return step[n];
	}
};
