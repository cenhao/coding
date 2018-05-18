// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
	char internal_buf[4];
	int nxt, bn;
	bool hasMore() {
		if (nxt < bn) { return true; }
		if (bn > 0) {
			nxt = 0;
			bn = read4(internal_buf);
			return bn > 0;
		}
		return false;
	}
public:
	Solution() { bn = nxt = 1; }
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
		int pos = 0;
		while (pos<n && hasMore()) {
			for (; nxt<bn && pos<n; ++pos, ++nxt) {
				buf[pos] = internal_buf[nxt];
			}
		}

		return pos;
    }
};
