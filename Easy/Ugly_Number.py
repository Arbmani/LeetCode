class Solution:
    '''
    [Easy Problem]

        An ugly number is a positve integer which does not have a prime factor other than 2,3, and 5.

        Given an integer n, return true if n is an ugly number.
    
    '''

    def isUgly(self, n: int) -> bool:
        if n <= 0: return False

        for factor in (2, 3, 5):
            while n % factor == 0:
                n //= factor
        return n == 1

if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().isUgly(6)}")

    print(f"Want : {True}, Was : {Solution().isUgly(1)}")

    print(f"Want : {False}, Was : {Solution().isUgly(14)}")