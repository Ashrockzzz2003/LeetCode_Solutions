class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)

        for i in range(len(strs)):
            # Sort the word
            word = ''.join(sorted(strs[i]))

            # Add Index to respective anagram
            anagrams[word].append(i)

        final_ans = []

        for anagram in anagrams:
            final_ans.append([])

            for index in anagrams[anagram]:
                final_ans[-1].append(strs[index])
        
        return final_ans


        return []

