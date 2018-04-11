class Solution {
public:
	void reverseWords(string &s) {
		int len = s.length();
		string tmp;
		int sta = 0;
		bool pending = false;
		while (s[sta] == ' ') { ++sta; }
		for (int i=sta; i<len; ++i) {
			if (s[i] == ' ') {
				pending = true;
				continue;
			}
			if (pending) {
				pending = false;
				tmp += ' ';
			}
			tmp += s[i];
		}
		s = move(tmp);
		len = s.length();
		for (int l=0, r=len-1; l<r; ++l, --r) {
			swap(s[l], s[r]);
		}
		for (int i=0, last=0; i<=len; ++i) {
			if (i==len || s[i] == ' ') {
				for (int l=last, r=i-1; l<r; ++l, --r) { swap(s[l], s[r]); }
				last = i+1;
			}
		}

		return;
	}
};
