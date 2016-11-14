#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
		bool repeatedSubstringPattern(string str) {
			vector<bool> isPrime(str.length(), true);
			vector<int> prime(str.length());
			int pcnt = 0, len = str.length();

			for (int i=2; i<=len; ++i) {
				if (!isPrime[i]) { continue; }
				prime[pcnt++] = i;
				for (int j=i+i; j<=len; j+=i) { isPrime[j] = false; }
			}

			for (int i=0; i<pcnt; ++i) {
				if ((len % prime[i]) != 0) { continue; }
				int step = len / prime[i];
				bool stop = false;
				for (int i1=0; i1<step && !stop; ++i1) {
					for (int i2=step+i1; i2<len; i2+=step) {
						if (str[i2] != str[i1]) {
							stop = true;
							break;
						}
					}
				}

				if (!stop) { return true; }
			}

			return false;
		}
};

int main() {
	string str;
	while (cin >> str) {
		Solution sol;
		cout << (sol.repeatedSubstringPattern(str) ? 1 : 0) << endl;
	}

	return 0;
}
