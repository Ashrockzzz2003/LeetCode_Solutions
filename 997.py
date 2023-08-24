class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # trusts 0
        # is trusted by everybody else
        # Exactly only one judge

        # edge from u to v if u trusts v
        if n == 0:
            return -1

        if n == 1:
            if len(trust) == 0:
                return 1
            return trust[0][1]

        trusts = [0 for i in range(n)]
        trusted_by = [0 for i in range(n)]
        
        for (u, v) in trust:
            trusts[u - 1] += 1
            trusted_by[v - 1] += 1
        
        for i in range(n):
            if trusts[i] == 0 and trusted_by[i] == n - 1:
                return i + 1
        
        return -1
        

        

        


