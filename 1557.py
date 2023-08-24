import numpy as np

class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        
        inDegree = np.zeros(n)

        for (u, v) in edges:
            inDegree[v] += 1
        
        minVertices = []
        for i in range(n):
            if inDegree[i] == 0:
                minVertices.append(i)
        
        return minVertices
