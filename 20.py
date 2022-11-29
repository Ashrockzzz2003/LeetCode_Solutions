class Solution:
    def push(self, S,x):
        S.append(x)
        return S
        
    def pop(self, S):
        removed_element = S.pop(-1)
        return removed_element
        
    def is_empty(self, L):
        return L==[]
        
    def isValid(self, word: str) -> bool:
        S=[]
        
        opening = ["(","[","{"]
        closing = [")","]","}"]
        
        d = dict(zip(closing,opening))
        
        for i in word:
            if i in opening:
                self.push(S,i)
            if i in closing:
                if not self.is_empty(S):
                    if d[i]!=self.pop(S):
                        return False
                else:
                    return False
        if not self.is_empty(S):
            return False
            
        return True
