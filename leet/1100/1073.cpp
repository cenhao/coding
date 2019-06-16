class Solution {
public:
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
		int len1 = arr1.size(), len2 = arr2.size();
		int len = max(len1, len2);
		reverse(arr1.begin(), arr1.end());
		reverse(arr2.begin(), arr2.end());

		vector<int> ans;

		for (int i=0; i<len; ++i) {
			int v1 = i >= len1 ? 0 : arr1[i];
			int v2 = i >= len2 ? 0 : arr2[i];
			ans.push_back(v1 + v2);
		}

		for (int i=0; i<ans.size(); ++i) {
			if (ans[i] > 1) {
				ans[i] %= 2;
				if (i+1<ans.size() && ans[i+1]>0) {
					--ans[i+1];
				} else {
					while (ans.size() <= i+2) {
						ans.push_back(0);
					}

					ans[i+1] += 1;
					ans[i+2] += 1;
				}
			}
		}

		while (ans.size() > 1 && ans[ans.size()-1] == 0) {
			ans.pop_back();
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};
