class Solution:
    def countGoodStrings(self, low, high, zero, one):
        self.mod = 1000000007
        dp = [-1] * (high + 1)
        ans = 0
        for i in range(low, high + 1):
            ans = (ans + self.solve(i, zero, one, dp)) % self.mod
        return ans
    def solve(self, ind, zero, one, dp):
        if ind == 0: return 1
        if ind < 0: return 0
        if dp[ind] != -1: return dp[ind] % self.mod
        forZero = self.solve(ind - zero, zero, one, dp)
        forOne = self.solve(ind - one, zero, one, dp)
        dp[ind] = (forZero + forOne) % self.mod
        return dp[ind]