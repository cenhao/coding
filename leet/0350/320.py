class Solution:
    def dfs(self, word, idx, buf, ans):
        if idx >= len(word):
            pos, s = 0, ''
            for item in buf:
                if isinstance(item, int):
                    s += str(item)
                    pos += item
                else:
                    s += item
            ans.append(s)
            return
        buf.append(word[idx])
        self.dfs(word, idx+1, buf, ans)
        buf.pop()
        if len(buf) > 0 and isinstance(buf[-1], int):
            buf[-1] += 1
            self.dfs(word, idx+1, buf, ans)
            buf[-1] -= 1
        else:
            buf.append(1)
            self.dfs(word, idx+1, buf, ans)
            buf.pop()

    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        ans, buf = [], []
        self.dfs(word, 0, buf, ans)
        return ans

sol = Solution()
print(sol.generateAbbreviations("word"))
