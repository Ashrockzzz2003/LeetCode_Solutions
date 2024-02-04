class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m = len(s)
        n = len(t)

        if (m < n):
            return ""
        
        if (s == t):
            return s

        # s = ADOBECODEBANC
        # t = ABC
        # Smallest Substring in s such that all chararters of t (even duplicates) are included in that.
        # OBSERVATION
        # min_length of such window = len(t) = n

        latest_start_index = 0
        final_index = -1
        final_len = m + 2

        s_freq = defaultdict(int)
        t_freq = defaultdict(int)

        for char in t:
            t_freq[char] += 1
        
        current_length = 0
        for i in range(m):
            s_freq[s[i]] += 1

            if s_freq[s[i]] <= t_freq[s[i]]:
                current_length += 1
            
            if current_length == n:
                # We have an answer now.

                while ((s_freq[s[latest_start_index]] > t_freq[s[latest_start_index]]) or (t_freq[s[latest_start_index]] == 0)):
                    
                    if s_freq[s[latest_start_index]] > t_freq[s[latest_start_index]]:
                        s_freq[s[latest_start_index]] -= 1
                    
                    latest_start_index += 1

                if i - latest_start_index + 1 < final_len:
                    final_len = i - latest_start_index + 1
                    final_index = latest_start_index
        

        if final_index == -1:
            # No Answer was found.
            return ""
        
        else:
            return s[final_index:final_index + final_len]



                

