class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        # graph = aList
        pathList = []

        def DFSPath(u, path):
            if u == len(graph) - 1:
                pathList.append(path)
                return
            
            for v in graph[u]:
                DFSPath(v, path + [v])
            
        DFSPath(0, [0])

        return pathList

        
