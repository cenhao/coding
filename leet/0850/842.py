class Solution:
    def dfs(self, s, cur, ans):
        if cur >= len(s): return len(ans) >= 3
        for i in range(min(len(s)-cur, 10)):
            ss = s[cur:cur+i+1]
            num, l = int(ss), len(ans)
            if num>0x7fffffff or str(num)!=ss: break
            if l>=2 and num>ans[l-1]+ans[l-2]: break
            if l<2 or num==ans[l-1]+ans[l-2]:
                ans.append(num)
                if self.dfs(s, cur+i+1, ans): return True
                ans.pop()
        return False

    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        ans = []
        self.dfs(S, 0, ans)
        return ans


sol = Solution()
print(sol.splitIntoFibonacci("417420815174208193484163452262453871040871393665402264706273658371675923077949581449611550452755"))
