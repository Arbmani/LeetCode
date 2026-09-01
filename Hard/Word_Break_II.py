from typing import List 
from collections import defaultdict
class Solution:
    '''
        Given a string "s" and a dictionary of strings "wordDict", add spaces
        in "s" to construct a sentence where each word is a valid dictionary word.

        Note that the same word in the dictionary may be reused multiple times in the segmentation.
    
    '''
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        cache  = defaultdict(list)
        for word in wordDict:
            for start in range(len(s) - len(word) + 1):
                end = start + len(word) - 1
                if s[start:end + 1] == word:
                    cache[start].append((word, end))
        result = []
        def Depth_First_Search(path: str, start_index: int) -> None:
            if start_index == len(s):
                result.append(path)
            for (word, end) in cache[start_index]:
                if len(path) != 0:
                    Depth_First_Search(path + " " + word, end + 1)
                else:
                    Depth_First_Search(word, end + 1)
        Depth_First_Search(path="", start_index=0)
        return result


if __name__ == "__main__":
    def test(correct_answer, my_answer):
        correct_answer.sort()
        my_answer.sort()
        assert(correct_answer == my_answer)

    test(["cats and dog","cat sand dog"], Solution().wordBreak(s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]))
    test(["pine apple pen apple","pineapple pen apple","pine applepen apple"], Solution().wordBreak(s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]))
    test([], Solution().wordBreak(s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]))

    print("All Tested Passed")
        