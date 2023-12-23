class Solution:
    def isPathCrossing(self, path: str) -> bool:
        theValue = {
            "N": (0, 1),
            "E": (1, 0),
            "W": (-1, 0),
            "S": (0, -1)
        }

        x, y = 0, 0

        visitedCoordinates = set()
        visitedCoordinates.add((0, 0))

        for direction in path:
            x += theValue[direction][0]
            y += theValue[direction][1]

            if (x, y) in visitedCoordinates:
                return True
            
            visitedCoordinates.add((x, y))
        
        return False
            
        
        return False
        
