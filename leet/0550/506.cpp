#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
	struct Athlete {
		int score;
		int rank;
		int order;
	};
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<Athlete> a(nums.size());
		for (int i=0; i<nums.size(); ++i) {
			a[i].score = nums[i];
			a[i].order = i;
		}

		sort(a.begin(), a.end(), [](const Athlete &a1, const Athlete &a2) {
			return a1.score > a2.score;
		});

		for (int i=0; i<nums.size(); ++i) {
			a[i].rank = i + 1;
		}

		sort(a.begin(), a.end(), [](const Athlete &a1, const Athlete &a2) {
			return a1.order < a2.order;
		});

		vector<string> ans(nums.size());
		for (int i=0; i<nums.size(); ++i) {
			if (a[i].rank == 1) {
				ans[i] = "Gold Medal";
			} else if (a[i].rank == 2) {
				ans[i] = "Silver Medal";
			} else if (a[i].rank == 3) {
				ans[i] = "Bronze Medal";
			} else {
				ans[i] = move(to_string(a[i].rank));
			}
		}

		return ans;
	}
};

