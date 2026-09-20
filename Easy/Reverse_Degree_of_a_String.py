class Solution:
    '''
    [Easy Problem]

        Given a string "s" calculate its reverse degree.

        The reverse degree is calculated as follows:

        1.  For each character, multiply its position in the reversed ('a' = 26, 'b' = 25, ..., 'z' = 1)
            With its position in the string (1-indexed)

        2.  Sum these products for all characters in the string.

        Return the reverse degree of s.
    
    
    '''

    def reverseDegree(self, s: str) -> int:
        ans, len_s, ord_z = 0, len(s), ord('z')
        for index in range(len_s):
            ans += (1 + abs(ord(s[index]) - ord_z)) * (index + 1)
        return ans


if __name__ == "__main__":
    print(f"Want : {148}, Was : {Solution().reverseDegree(s = "abc")}")

    print(f"Want : {160}, Was : {Solution().reverseDegree(s = "zaza")}")