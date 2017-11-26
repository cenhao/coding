class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> tmp(asteroids.size());
		stack<int> st;
		int pos = 0;
		for (auto a : asteroids) {
			if (a >= 0) {
				st.push(a);
				tmp[pos++] = a;
			} else {
				int ra = abs(a);
				bool keep = true;
				while (!st.empty()) {
					int t = st.top();
					if (t < ra) {
						st.pop();
						--pos;
					} else {
						if (t == ra) {
							st.pop();
							--pos;
						}
						keep = false;
						break;
					}
				}

				if (keep) {
					tmp[pos++] = a;
				}
			}
		}

		vector<int> ans(pos);
		for (int i=0; i<pos; ++i) { ans[i] = tmp[i]; }
		return ans;
	}
};
