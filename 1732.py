class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max_altitude = 0
        altitude = 0

        for i in range(len(gain)):
            altitude += gain[i]
            if altitude > max_altitude:
                max_altitude = altitude
        
        return max_altitude
