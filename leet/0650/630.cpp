/*
 * 1. sort the courses by their last date
 * 2. iterate each course, and try to take this course
 * 3. if it's impossible to take this course in the current setup, abandon the 
 * course that requires longest time.
 *
 * With this approach, it's guaranteed that a optimal solution can be found
 * for using the last date of the current course as the last date.
 */
class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(), courses.end(), [](const vector<int> &v1, const vector<int> &v2) {
			return v1[1] < v2[1];
		});

		priority_queue<int> pq;
		int used = 0;
		for (auto &c : courses) {
			used += c[0];
			pq.push(c[0]);
			while (used > c[1]) { used -= pq.top(); pq.pop(); }
		}

		return pq.size();
	}
};
