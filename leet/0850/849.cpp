class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		vector<int> pos;
		for (int i=0; i<seats.size(); ++i) {
			if (seats[i]) { pos.push_back(i); }
		}
		int mx = -1;
		for (int i=1; i<pos.size(); ++i) {
			mx = max(mx, (pos[i]+pos[i-1])/2-pos[i-1]);
		}

		if (pos.front() != 0) { mx = max(mx, pos.front()); }
		if (pos.back() != seats.size()-1) { mx = max(mx, int(seats.size())-1-pos.back()); }
		return mx;
	}
};
