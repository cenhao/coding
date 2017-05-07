class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> hs;
		for (int i=0; i<candies.size(); ++i) { hs.insert(candies[i]); }
		return min(candies.size()/2, hs.size());
	}
};
