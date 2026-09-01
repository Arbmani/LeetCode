from typing import List 
class Solution:
    '''
        Given a string "s" and a dictionary of strings "wordDict", return "true" if "s" can be
        segmented into a space-separated sequence of one or more dictionary words.

        Note that the same word in the dictionary may be reused multiple times in the segmentation.
    '''

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        lengths = {len(word) for word in wordDict}

        cache       = [False] * (len(s) + 1)
        cache[0]    = True 

        for end in range(1, len(s) + 1):
            for length in lengths:
                if (length <= end        and 
                    cache[end - length]  and
                    s[end - length: end] in wordSet):
                    cache[end] = True
                    break
        return cache[-1]

if __name__ == "__main__":
    print(f"Correct answer is : True, my anser is : {Solution().wordBreak(s = "leetcode", wordDict = ["leet","code"])}")
    print(f"Correct answer is : True, my anser is : {Solution().wordBreak(s = "applepenapple", wordDict = ["apple","pen"])}")
    print(f"Correct answer is : False, my anser is : {Solution().wordBreak(s = "catsandog", wordDict = ["cats","dog","sand","and","cat"])}")