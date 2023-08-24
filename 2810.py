class Solution:
    def finalString(self, s: str) -> str:
        final_string = []
        for c in s:
            if c == "i":
                final_string = final_string[::-1]
            else:
                final_string += [c]
        
        return "".join(final_string)
                
            