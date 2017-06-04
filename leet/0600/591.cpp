class Solution {
public:
	bool tag(string &code, int start, int &end) {
		if (start >= code.length()) { return false; }
		if (code[start] != '<') { return false; }

		end = start + 1;
		string tagname;
		while (end < code.length() && code[end] != '>') {
			if (code[end] < 'A' && code[end] > 'Z') { return false; }
			tagname += code[end++];
		}
		++end; // skip >

		if (tagname.length() <= 0 || tagname.length() > 9 || end >= code.length()) { return false; }

		while (end < code.length()) {
			while (end < code.length() && code[end] != '<') { ++end; }

			if (end >= code.length()-1 || code[end] != '<') { return false; }
			++end; // skip <

			if (code[end] == '!') {
				if (!cdata(code, end-1, end)) { return false; }
			} else if (code[end] == '/') {
				++end; // skip /
				string ct;
				while (end < code.length() && code[end] != '>') {
					if (code[end] < 'A' || code[end] > 'Z') { return false; }
					ct += code[end++];
				}

				++end; // skip >
				return ct == tagname;
			} else {
				if (!tag(code, end-1, end)) { return false; }
			}
		}

		return false;
	}

	bool cdata(string &code, int start, int &end) {
		if (start >= code.length()) { return false; }
		if (code.substr(start, 9) != "<![CDATA[") { return false; }
		end = start + 9;

		while (end < code.length()-2
			   && !(code[end] == ']' && code[end+1] == ']' && code[end+2] == '>')) {
			++end;
		}

		if (end >= code.length()) { return false; }
		end += 3;
		return true;
	}

	bool isValid(string code) {
		int end;
		return tag(code, 0, end) && end == code.length();
	}
};
