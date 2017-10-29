class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int sz = bits.size();
		bool last = false;
		for (int i=0; i<sz; ++i) {
			last = bits[i] == 0;
			if (bits[i] != 0) { ++i; }
		}

		return last;
	}
};
