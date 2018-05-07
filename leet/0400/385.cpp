/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
	NestedInteger process(string &s, int &cur) {
		NestedInteger nl;
		if (s[cur] == '[') {
			do {
				if (s[++cur] == ']') { break; }
				nl.add(process(s, cur));
			} while (s[cur] != ']');
			++cur;
		} else {
			int v = 0;
			bool neg = false;
			if (s[cur] == '-') {
				++cur;
				neg = true;
			}
			while (s[cur]>='0' && s[cur]<='9') {
				v = s[cur++]-'0' + v * 10;
			}
			nl.setInteger(neg ? -v : v);
		}
		return nl;
	}
    NestedInteger deserialize(string s) {
		int cur = 0;
		return process(s, cur);
    }
};
