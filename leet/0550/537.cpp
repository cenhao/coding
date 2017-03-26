class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int rn[2], cn[2];
		sscanf(a.c_str(), "%d+%di", &rn[0], &cn[0]);
		sscanf(b.c_str(), "%d+%di", &rn[1], &cn[1]);
		int r = rn[0] * rn[1] - cn[0] * cn[1];
		int c = rn[0] * cn[1] + cn[0] * rn[1];
		char buff[1024];
		snprintf(buff, sizeof(buff), "%d+%di", r, c);
		return string(buff);
	}
};
