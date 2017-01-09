#include <cstdio>
using namespace std;

class Solution {
	public:
		int findComplement(int num) {
			if (num == 0) { return 1; }

			int tmp = num, shift = 0;
			while (tmp > 0) {
				++shift;
				tmp >>= 1;
			}

			int mask = (1 << shift) - 1;
			return (~num) & mask;
		}
};

int main() {
	int n;
	while (EOF != scanf("%d", &n)) {
		Solution sol;
		printf("%d\n", sol.findComplement(n));
	}

	return 0;
}
