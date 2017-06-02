class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int mx = list1.size() + list2.size();
		unordered_map<string, int> hm;
		for (int i=0; i<list1.size(); ++i) {
			hm.insert(move(make_pair(list1[i], i)));
		}

		vector<string> ans;
		for (int i=0; i<list2.size(); ++i) {
			auto it = hm.find(list2[i]);
			if (it != hm.end()) {
				int sum = it->second + i;
				if (sum < mx) {
					ans.clear();
				}
				if (sum <= mx) {
					ans.push_back(move(list2[i]));
					mx = sum;
				}
			}
		}

		return ans;
	}
};
