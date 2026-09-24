class Solution:
    '''
    [Easy Problem]

        Given an integer n, return true if it is a power of four. Otherwise, return False.

        An integer n is a power of four, if there exists an integer x, such that n == 4^x  
    
    '''
    def isPowerOfFour(self, n: int) -> bool:
        curr = 1
        while curr < n:
            curr *= 4
        return curr == n


if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().isPowerOfFour(16)}")
    print(f"Want : {False}, Was : {Solution().isPowerOfFour(5)}")
    print(f"Want : {True}, Was : {Solution().isPowerOfFour(1)}")

