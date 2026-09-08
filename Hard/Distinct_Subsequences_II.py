class Solution:
    '''
    [Hard Problem]

        Given a string "s", return the number of distinct non-empty subsequences of "s".
        Since the answer may be very large, return it modulo (10^9 + 7).

        A subsequence of a string is a new string that is formed from the original string by deleting
        some (can be none) of the characters without disturbing the relative positions of the
        remaining characters (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
    
    
    '''

    def distinctSubseqII(self, s: str) -> int:
        cache, modulo, result = [0] * 26, 10**9 + 7, 0
        for char in s:
            index = ord(char) - 97
            new = (result + 1) % modulo
            result = (result - cache[index] + new) % modulo
            cache[index] = new 
        return result


if __name__ == "__main__":
    print(f"Want : {7}, Was : {Solution().distinctSubseqII(s = "abc")}")

    print(f"Want : {6}, Was : {Solution().distinctSubseqII(s = "aba")}")

    print(f"Want : {3}, Was : {Solution().distinctSubseqII(s = "aaa")}")