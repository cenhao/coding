class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int, int> hm;
		for (auto n: nums) {
			++hm[n];
			if (hm.size() >= 3) {
				unordered_map<int, int> tmp;
				for (auto &kvp: hm) {
					--kvp.second;
					if (kvp.second > 0) { tmp.insert(kvp); }
				}
				hm = move(tmp);
			}
		}
		for (auto &kvp: hm) { kvp.second = 0; }
		for (auto n: nums) {
			auto it = hm.find(n);
			if (it != hm.end()) { ++it->second; }
		}
		int requirement = nums.size() / 3;
		vector<int> ans;
		for (auto &kvp: hm) {
			if (kvp.second > requirement) {
				ans.push_back(kvp.first);
			}
		}

		return ans;
	}   
};

