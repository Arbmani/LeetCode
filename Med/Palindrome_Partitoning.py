from typing import List 

class Solution:
    '''
        Given a string "s", partition "s" such that every substring of the 
        partition is a palindrome. Return all possible palindrome partitioning of "s".
    
    '''

    def partition(self, s: str) -> List[List[str]]:
        cache = [[False] * len(s) for _ in range(len(s))]
        # Pre Processing
        for sub_string_len in range(1, len(s) + 1):
            for sub_string_start in range(len(s) - sub_string_len + 1):
                sub_string_end = sub_string_start + sub_string_len - 1
                if s[sub_string_start] == s[sub_string_end] and (
                    sub_string_len <= 2 or 
                    cache[sub_string_start + 1][sub_string_end - 1]):
                    cache[sub_string_start][sub_string_end] = True 
        result  = []
        path    = []

        def Depth_First_Search(start: int) -> None:
            if start == len(s):
                result.append(path.copy())
                return

            for end in range(start, len(s)):
                if cache[start][end]:
                    path.append(s[start:end + 1])
                    Depth_First_Search(end + 1)
                    path.pop()
        Depth_First_Search(0)
        return result



if __name__ == "__main__":
    print(Solution().partition(s = "aab"))