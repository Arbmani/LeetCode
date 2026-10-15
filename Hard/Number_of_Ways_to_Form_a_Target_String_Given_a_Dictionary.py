from collections import defaultdict
class Solution:
    '''
        [Hard Problem]
    
            You are given a list of strings of the same length words and a string target.

            Your task is to form target using the given words under the following rules:

            -   target should be formed from left to right.

            -   To form the ith character (0-indexed) of target, 
                you can choose the kth character of the jth string in words if target[i] = words[j][k].

            -   Once you use the kth character of the jth string of words, 
                you can no longer use the xth character of any string in words where x <= k. 
                In other words, all characters to the left of or at index k become unusuable for every string.

            -   Repeat the process until you form the string target.

            Notice that you can use multiple characters from the same string in words provided the conditions above are met.

            Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.
    
    
    
    '''


    def numWays(self, words: list[str], target: str) -> int:
        modulo = 10**9 + 7
        count = defaultdict(int)
        for word in words:
            for (index, character) in enumerate(word):
                count[(index, character)] += 1
        dp = {}
        def dfs(i, k):
            if i == len(target)   : return 1
            if k == len(words[0]) : return 0
            if (i, k) in dp       : return dp[(i, k)]

            c = target[i]
            dp[(i, k)]  = dfs(i, k + 1) 
            dp[(i, k)] += (count[(k, c)] *  (dfs(i + 1, k + 1)))
            return dp[(i, k)] % modulo
        
        return dfs(0, 0)



if __name__ == "__main__":
    print(f"Want : {6}, Was : {Solution().numWays(words = ["acca","bbbb","caca"], target = "aba")}")
    print(f"Want : {4}, Was : {Solution().numWays(words = ["abba","baab"], target = "bab")}")