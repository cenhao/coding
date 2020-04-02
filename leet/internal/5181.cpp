class Solution {
public:
	int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		int sz = distance.size();
		int sm1 = 0, sm2 = 0;
		for (int i=start; i!=destination; i=(i+1)%sz) {
			sm1 += distance[i];
		}
		for (int i=start; i!=destination; i=(i-1+sz)%sz) {
			sm2 += distance[(i-1+sz)%sz];
		}
		return min(sm1, sm2);
	}
};
