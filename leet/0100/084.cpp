class Solution {
public:
	struct SItem {
		int h, pos;
	};
	int largestRectangleArea(vector<int>& heights) {
		stack<SItem> s;
		int mx = 0, sz = heights.size();
		for (int i=0; i<=sz; ++i) {
			int last = i;
			while (!s.empty() && (i==sz || heights[i]<s.top().h)) {
				SItem tmp = s.top(); s.pop();
				mx = max(mx, tmp.h * (i-tmp.pos));
				last = tmp.pos;
			}

			if (i == sz) { break; }
			SItem tmp = { heights[i], last };
			s.push(tmp);
		}

		return mx;
	}
};
