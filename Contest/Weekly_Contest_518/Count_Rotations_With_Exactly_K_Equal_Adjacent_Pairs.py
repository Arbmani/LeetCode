class Solution:
    '''
    [Easy Problem]
    
        You are given a string "s" of length "n" and an integer "k".

        A cyclic rotation of "s" is obtained by choosing a prefix of "s" whoose length
        is between 0 and "n - 1" (inclusive), and moving it to the end of the string
        while preserving the orders of all characters.

        For every cyclic rotation of "s", let its score be the number of indices "i"
        such that "0 <= i < n - 1" and the characters at position "i" and "i + 1"
        are equal.

        Return the number of cyclic rotations of "s" whoose score equals "k". 


    '''

    def countRotations(self, s: str, k: int) -> int:
        equal_pairs = 0
        for index in range(len(s)):
            if s[index] == s[(index + 1) % len(s)]:
                equal_pairs += 1

        equal_cuts      = equal_pairs
        different_cuts  = len(s) - equal_cuts
        if k == equal_pairs - 1:
            return equal_cuts
        if k == equal_pairs:
            return different_cuts
        return 0


if __name__ == "__main__":
    print(f"Want {2}, Was {Solution().countRotations(s = "aab", k = 1)}")

    print(f"Want {1}, Was {Solution().countRotations(s = "abca", k = 0)}")