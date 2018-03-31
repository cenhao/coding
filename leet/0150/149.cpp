/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

/*
// an imcomplete O(n^2) solution
class Solution {
public:
	string hash_func(int a, int b) {
		return to_string(a) + "/" + to_string(b);
	}
	int gcd(int a, int b) {
		while (b != 0) {
			int tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	}
	int find(int x, vector<int> &f) {
		return (f[x] != x) ? (f[x] = find(f[x], f)) : f[x];
	}
	int merge(int x, int y, vector<int> &f, vector<int> &w) {
		if (w[x] > w[y]) {
			w[x] += w[y];
			f[y] = x;
			return w[x];
		} else {
			w[y] += w[x];
			f[x] = y;
			return w[y];
		}
	}
    int maxPoints(vector<Point>& points) {
		int sz = points.size();
		if (sz == 0) { return 0; }
		unordered_map<string, vector<pair<int, int>>> hm;
		for (int i=0; i<sz; ++i) {
			for (int j=i+1; j<sz; ++j) {
				int dx = points[i].x - points[j].x;
				int dy = points[i].y - points[j].y;
				if (dx == 0) {
					dy = 1;
				} else if (dy == 0) {
					dx = 1;
				} else {
					int d = gcd(abs(dx), abs(dy));
					dx /= d;
					dy /= d;
					if (dx < 0) { dx = -dx; dy = -dy; }
				}
				string hv = hash_func(dx, dy);
				hm[hv].push_back(make_pair(i, j));
			}
		}

		vector<int> vis(sz, 0);
		vector<int> f(sz);
		vector<int> w(sz);
		int cnt = 0, ans = 1;
		for (auto &kvp: hm) {
			++cnt;
			auto &vp = kvp.second;
			for (auto &p: vp) {
				if (vis[p.first] != cnt) {
					f[p.first] = p.first;
					w[p.first] = 1;
					vis[p.first] = cnt;
				}
				if (vis[p.second] != cnt) {
					f[p.second] = p.second;
					w[p.second] = 1;
					vis[p.second] = cnt;
				}

				int fx = find(p.first, f), fy = find(p.second, f);
				if (fx != fy) {
					ans = max(ans, merge(fx, fy, f, w));
				}
			}
		}

		return ans;
    }
};
*/

class Solution {
public:
	int gcd(int a, int b) {
		while (b != 0) {
			int tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	}
	int maxPoints(vector<Point>& points) {
		int sz = points.size();
		if (sz <= 2) { return sz; }
		int ans = 1;
		for (int i=0; i<sz; ++i) {
			int same = 0;
			unordered_map<uint64_t, int> hm;
			for (int j=i+1; j<sz; ++j) {
				int dx = points[i].x - points[j].x, dy = points[i].y - points[j].y;
				if (dx == 0 && dy == 0) {
					++same;
					continue;
				} else if (dx == 0) {
					dy = 1;
				} else if (dy == 0) {
					dx = 1;
				} else {
					int d = gcd(abs(dx), abs(dy));
					dx /= d; dy /= d;
					if (dx < 0) { dx = -dx; dy = -dy; }
				}
				uint64_t hv = (uint64_t(dx)<<32) | (uint32_t(dy));
				++hm[hv];
			}
			ans = max(ans, same+1);
			for (auto &kvp: hm) {
				ans = max(ans, 1+same+kvp.second);
			}
		}

		return ans;
	}
};
