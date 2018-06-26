class Solution {
	struct Car { int p, v; };
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int sz = position.size();
		vector<Car> cars(sz);
		for (int i=0; i<sz; ++i) {
			cars[i].p = position[i];
			cars[i].v = speed[i];
		}

		sort(cars.begin(), cars.end(), [](const Car &c1, const Car &c2) {
			return c1.p != c2.p ? c1.p < c2.p : c1.v < c2.v;
		});

		int64_t lp = target+1, lv = 0x7fffffff, cnt = 0;
		for (int i=sz-1; i>=0; --i) {
			if (cars[i].v > lv) {
				int diff = cars[i].v - lv;
				if ((lp-cars[i].p)*lv <= (target-lp)*diff) {
					continue;
				}
			}

			++cnt;
			lp = cars[i].p;
			lv = cars[i].v;
		}

		return cnt;
	}
};
