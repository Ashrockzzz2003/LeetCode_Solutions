class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        monsterComingTime = [0 for i in range(len(dist))]

        for i in range(len(dist)):
            monsterComingTime[i] = dist[i] / speed[i]

        monsterComingTime.sort()

        for i in range(len(dist)):
            if i >= monsterComingTime[i]:
                return i
        
        return len(dist)