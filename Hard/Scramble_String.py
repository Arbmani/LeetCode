class Solution:
    cache = {}
    def isScramble(self, s1: str, s2: str) -> bool:
        n = len(s1)
        if s1 == s2:                            # check if the two strings are equal
            return True 
        a, b, c = [0] * 26, [0] * 26, [0] * 26
        if (s1 + s2) in self.cache:
            return self.cache[s1 + s2]
        for i in range(1, n):
            j = n - i
            a[ord(s1[i-1]) - ord('a')]  += 1
            b[ord(s2[i-1]) - ord('a')]  += 1
            c[ord(s2[j]) - ord('a')]    += 1

            if a == b and self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                self.cache[s1 + s2] = True
                return True
            if a == c and self.isScramble(s1[:i], s2[j:]) and self.isScramble(s1[i:], s2[:j]):
                self.cache[s1 + s2] = True
                return True

        self.cache[s1 + s2] = False
        return False
'''
    There are several ways to solve the Scramble String problem

    - Recursion with memoization:
        The idea is to recursively check all possible splits of the two strings,
        and memoize the results to avoid recomputing the same substring multiple times.
    
    - Dynamic programming:
        This approach involves building a 3D table to store the results of all possible
        substrings of the two strings. The table is filled in a bottom-up manner, starting
        with the smallest substring and building up to the largest substrings. The table can 
        then be used to check if the two strings are scrambled versions of each other.

    - Top-down Dynamic programming:
        This approach is similar to recursion and memoization, but uses a 3D table to 
        store the results of all possible substrings of the two strings. The table is filled
        in a top-down manner, starting with the largest substrings and building down to the smallest
        substrings. The table can then be used to check if the two strings are scrambled version 
        of each other. 

    - Breath First Search:
        This approach involves using a queue to generate all possible scrambled versions of one of
        the strings, and checking if any of them match the other string. The idea is to generate
        all possible substrings of the first string, and then generate all possible permutations
        of each substring. The resulting strings can then be checked to see if they match
        the second string. 








'''

if __name__ == "__main__":
    sol = Solution()
    print(sol.isScramble(s1 = "great", s2 = "rgeat"))