class Solution:
    def mySqrt(self, x: int) -> int:
        l = 1
        r = x
        n = 0

        while l <= r:

            mid = l + (r - l) // 2
            if(mid*mid <= x):
                n = mid
                l = mid + 1
            else:
                r = mid - 1
        
        return n
