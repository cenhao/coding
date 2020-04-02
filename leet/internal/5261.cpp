/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
		vector<int64_t> cnt(26, 0);
		for (auto c: text) { ++cnt[c-'a']; }
		int sz = fonts.size();
		int l = 0, r = sz-1;
		while (l <= r) {
			int m = (l + r) / 2;
			int64_t tot_w = 0;
			for (int i=0; i<26; ++i) {
				int cw = fontInfo.getWidth(fonts[m], 'a'+i);
				tot_w += cw * cnt[i];
			}
			int64_t mx_h = fontInfo.getHeight(fonts[m]);

			if (tot_w>w || mx_h>h) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		return r==-1 ? -1 : fonts[r];
    }
};
