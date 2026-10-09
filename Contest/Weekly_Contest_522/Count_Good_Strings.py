class Solution:
    '''
    [Hard Problem]

        You are given an integer n.

        A string is considered good if it consists only of the characters 
        'a' and 'b', and one of the following holds:

        -   It contains exactly one distinct character, and its length is odd.

        -   It can be written as s = s1 + s2, where s1 and s2 are non-empty good strings, 
            and the last character of s1 is different from the first character of s2.

        Return the number of good strings of length n, modulo 10^9 + 7.

        Here, + denotes string concatenation.
    
    '''
    def countGoodStrings(self, n: int) -> int:
        modulo = 10**9 + 7
        def fib(k):
            if k == 0: return (0, 1)

            a, b = fib(k // 2)
            c    = a * (2 * b - a) % modulo
            d    = (a * a + b * b) % modulo

            if k % 2: return (d, (c + d) % modulo)
            return (c, d)
        return 2 * fib(n)[0] % modulo


    def countGoodStrings_slow(self, n: int) -> int:
        modulo = 10**9 + 7
        if n <= 2: return 2
        prev1 = prev2 = 2
        for i in range(3, n + 1):
            curr = (prev1 + prev2) % modulo
            prev2 = prev1
            prev1 = curr 

        return prev1


if __name__ == "__main__":
    print(f"Want : {6}, Was : {Solution().countGoodStrings(n = 4)}")
    print(f"Want : {4}, Was : {Solution().countGoodStrings(n = 3)}")
    print(f"Want : {2}, Was : {Solution().countGoodStrings(n = 2)}")