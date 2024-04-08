from collections import defaultdict
from typing import List

class Solution:
    def bellmann_ford(self, G, v):
        """
        Relax all edges |V|-1 times
        """
        d = {}

        for u in G:
            d[u] = 10**9 + 7
        
        # for u, w in G[v]:
        #     d[u] = w
        
        # print(d)

        for i in range(len(G) - 1):
            for u in G:
                for v, w in G[u]:
                    if d[u] & w < d[v]:
                        d[v] = d[u] & w

        for u in d:
            if d[u] == 10**9 + 7:
                d[u] = -1
        
        return d

    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        G = defaultdict(list)

        for u in range(n):
            G[u] = []

        for u, v, w in edges:
            G[u].append([v, w])
            G[v].append([u, w])

        print(G)

        final_answer = []

        for u, v in query:
            if u == v:
                final_answer.append(0)
                continue

            d = self.dijkstra(G, u)
            final_answer.append(d[v])
        
        return final_answer
    

# n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]

n = 5
edges = [[0,1,7],[1,3,7],[1,2,1]]
query = [[0,3],[3,4]]

s = Solution()
print(s.minimumCost(n, edges, query))

n = 9
edges = [[0,4,7],[3,5,1],[1,3,5],[1,5,1]]
query = [[0,4],[1,5],[3,0],[3,3],[3,2],[2,0],[7,7],[7,0]]

s = Solution()
print(s.minimumCost(n, edges, query))

# [7,1,-1,0,-1,-1,0,-1]
# [7,1,-1,-1,-1,-1,-1,-1]


n = 3
edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]]
query = [[1,2]]

s = Solution()
print(s.minimumCost(n, edges, query))



