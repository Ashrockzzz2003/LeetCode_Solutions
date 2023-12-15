class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        source = set()
        destination = set()

        for u, v in paths:
            source.add(u)
            destination.add(v)
        
        return list(destination - source)[0]
        