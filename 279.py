class Solution:
    # Top Down approach with cache. TLE. So next trying bottom up.
    def recursivelyFindLeastSteps(self, n: int, dp: list) -> int:
        if dp[n] != -1:
            return dp[n]

        if n <= 0:
            return 0
        
        sq_root = int(n**0.5)

        if sq_root*sq_root == n:
            dp[n] = 1
            return dp[n]

        min_steps = n
        for i in range(sq_root, 0, -1):
            min_steps = min(min_steps, self.numSquares(n - (i*i)) + 1)
        
        dp[n] = min_steps
        return dp[n]

    def numSquares(self, n: int) -> int:
        # Greedy will not work
        # 12 -> largest square -> 9
        # 12 - 9 => 3 - 1 => 2 - 1 => 1 - 1 => 0 (4 steps)
        # 12 - 4 => 8 - 4 => 4 - 4 => 0 (3 steps)

        # TOP Down with cache. TLE
        # dp = [-1 for _ in range(n+1)]
        # return self.recursivelyFindLeastSteps(n, dp)

        # Bottom Up now
        dp = [0 for _ in range(n + 1)]

        # Perfect Squares we know the answer!
        i = 1
        while (i*i <= n):
            dp[i*i] = 1
            i += 1
        
        for i in range(1, n + 1):
            if dp[i] != 1:
                sq_root = int(math.sqrt(i))
                min_steps = i
                for j in range(1, sq_root + 1):
                    min_steps = min(min_steps, dp[j*j] + dp[i - (j*j)])
                
                dp[i] = min_steps
        
        return dp[n]


        
