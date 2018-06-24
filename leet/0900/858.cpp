class Solution {
public:
	int mirrorReflection(int p, int q) {
		int lr = 0, d = 0;
		while ((d % p)!=0 || (lr==0 && ((d/p)&1)==0)) {
			d += q;
			lr ^= 1;
		}

		if (lr == 0) { return 2; }
		return (d/p) & 1;
	}
};
