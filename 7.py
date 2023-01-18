class Solution:
    def reverse(self, x: int) -> int:
        x = list(str(x))
        if('-' in x):
            x.remove('-')
            x.reverse()

            x = "-" + "".join(x)
            x = int(x)
        else:
            x.reverse()

            x = "".join(x)
            x = int(x)
        
        if not abs(x)<1<<31:
            return 0

        return x
