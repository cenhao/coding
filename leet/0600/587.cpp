/*
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {
		auto cmp = [](const Point &p1, const Point &p2) -> bool {
			return p1.x == p2.x ? (p1.y < p2.y) : (p1.x < p2.x);
		};
		sort(points.begin(), points.end(), cmp);

		vector<Point> b, t; // bottom, top
		for (auto &p : points) {
			while (b.size() >= 2 && cross_prod(b[b.size()-2], b[b.size()-1], p) < 0) {
				b.pop_back();
			}
			b.push_back(p);
		}

		for (auto &p : points) {
			while (t.size() >= 2 && cross_prod(t[t.size()-2], t[t.size()-1], p) > 0) {
				t.pop_back();
			}
			t.push_back(p);
		}

		set<Point, decltype(cmp)> uniq(cmp);
		for (auto &p : b) { uniq.insert(p); }
		for (auto &p : t) { uniq.insert(p); }
		vector<Point> ans(uniq.begin(), uniq.end());
		return ans;
	}

	int cross_prod(const Point &p1, const Point &p2, const Point &p3) const {
		int x1 = p2.x - p1.x, y1 = p2.y - p1.y;
		int x2 = p3.x - p1.x, y2 = p3.y - p1.y;
		return x1 * y2 - x2 * y1;
	}
};
