class Solution:
    def largestGoodInteger(self, num: str) -> str:
        lastSeen = ""
        maxNumber = ""
        count = 1

        for n in num:
            if n == lastSeen:
                count += 1
                if count == 3 and (maxNumber == "" or maxNumber[0] < lastSeen):
                    maxNumber = lastSeen*3
            else:
                lastSeen = n
                count = 1
        
        return maxNumber