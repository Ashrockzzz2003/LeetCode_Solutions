class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        # rooms: aList

        visited = [False for i in range(len(rooms))]

        def DFS(source):
            if visited[source] == True:
                return

            visited[source] = True

            for v in rooms[source]:
                if visited[v] == False:
                    DFS(v)
        
        DFS(0)

        return all(visited)
        