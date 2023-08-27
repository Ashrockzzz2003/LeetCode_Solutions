class Solution:
    def maximizeTheProfit(self, n: int, offers: List[List[int]]) -> int:
        maxProfitSeenSoFar = [0] * (n + 1)
        offersEndingWith = [[] for _ in range(n)]
        for start, end, gold in offers:
            offersEndingWith[end].append((start, gold))
        
        for i in range(1, n + 1):
            # Don't take any offer. Retain the profit from the previous best sell of house.
            maxProfitSeenSoFar[i] = maxProfitSeenSoFar[i - 1]

            # Take the offer if it's better than not taking it
            for start, gold in offersEndingWith[i - 1]:
                maxProfitSeenSoFar[i] = max(maxProfitSeenSoFar[i], maxProfitSeenSoFar[start] + gold)

        return maxProfitSeenSoFar[n]
