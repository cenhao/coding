#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
	priority_queue<int> mxheap;
	priority_queue<int, vector<int>, greater<int>> mnheap;
	int count;

	public:
	MedianFinder() {
		count = 0;
	}

	// Adds a number into the data structure.
	void addNum(int num) {
		++count;
		if (!mnheap.empty() && num > mnheap.top()) {
			mnheap.push(num);
		} else {
			mxheap.push(num);
		}

		while (mxheap.size() < mnheap.size()) {
			mxheap.push(mnheap.top());
			mnheap.pop();
		}

		while (mxheap.size() > mnheap.size()+1) {
			mnheap.push(mxheap.top());
			mxheap.pop();
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (count & 1) {
			return mxheap.top();
		} else {
			return (mxheap.top() + mnheap.top()) / 2.0;
		}
	}
};

int main() {
	int n, v;
	while (cin >> n) {
		MedianFinder f;
		for (int i=0; i<n; ++i) {
			cin >> v;
			f.addNum(v);
			cout << f.findMedian() << endl;
		}
	}

	return 0;
}
