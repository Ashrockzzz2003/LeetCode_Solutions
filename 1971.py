class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True

        aList = [[] for i in range(n)]

        for (u, v) in edges:
            aList[u].append(v)
            aList[v].append(u)
        

        visited = set()

        stack = [source]

        while stack:
            v = stack.pop()
            if v == destination:
                return True
            visited.add(v)
            for neighbour in aList[v]:
                if neighbour == destination:
                    return True
                if neighbour not in visited:
                    stack.append(neighbour)
        
        return False
        
