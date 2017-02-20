#include <string>
using namespace std;

class Solution {
	public:
	bool detectCapitalUse(string word) {
		int cnt = 0;
		for (int i=0; i<word.length(); ++i) {
			if (word[i] >= 'A' && word[i] <= 'Z') {
				++cnt;
			}

		}

		return cnt == word.length() || cnt == 0 || (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z');
	}
};
