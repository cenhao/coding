class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		int sz = A.size();
		unordered_map<int, stack<int>> hm;
		for (int i=0; i<sz; ++i) {
			auto it = hm.find(B[i]);
			if (it == hm.end()) {
				it = hm.insert(make_pair(B[i], stack<int>())).first;
			}
			it->second.push(i);
		}

		vector<int> ans(sz);
		for (int i=0; i<sz; ++i) {
			auto it = hm.find(A[i]);
			ans[i] = it->second.top();
			it->second.pop();
		}

		return ans;
	}
};
