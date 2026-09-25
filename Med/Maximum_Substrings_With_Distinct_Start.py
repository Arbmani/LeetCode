class Solution:
    '''
    [Medium Problem]

        You are given a string "s" consisting of lowercase English letters.

        Return an integer denoting the maximum number of substrings you can split "s" into such that each substring
        starts  with a distinct character (i.e., no two substrings start with the same character)
    
    
    
    '''
    def maxDistinct(self, s: str) -> int:
        return len(set(s))

    def maxDistinct_slow(self, s: str) -> int:
        not_seen, ans, ord_a = [True] * 26, 0, ord('a') 
        for char in s:
            if not_seen[ord(char) - ord_a]:
                not_seen[ord(char) - ord_a] = False
                ans += 1
                if ans == 26:
                    return ans

        return ans


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().maxDistinct(s = "abab")}")
    print(f"Want : {4}, Was : {Solution().maxDistinct(s = "abcd")}")
    print(f"Want : {1}, Was : {Solution().maxDistinct( s = "aaaa")}")