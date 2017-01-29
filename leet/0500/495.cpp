#include <algorithm>
#include <vector>
using namespace std;

class Solution {
	public:
	int findPosisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.size() == 0) { return 0; }
		int sum = duration, last = timeSeries[0] + duration;
		for (int i=1, end=timeSeries.size(); i<end; ++i) {
			int tmp = timeSeries[i] + duration;
			int start = max(last, timeSeries[i]);
			sum += tmp - start;
			last = tmp;
		}

		return sum;
	}
};
