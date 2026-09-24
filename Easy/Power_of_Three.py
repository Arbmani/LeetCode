class Solution:
    '''
    [Easy Problem]

        Given an integer n, return true if it is a power of three. Otherwise, return false.

        An integer "n" is a power of three, if there exists an integer x such that n == 3^x

    
    
    '''

    def isPowerOfThree(self, n: int) -> bool:
        curr = 1
        while(curr < n):
            curr *= 3
        return curr == n

if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().isPowerOfThree(27)}")
    print(f"Want : {False}, Was : {Solution().isPowerOfThree(0)}")
    print(f"Want : {False}, Was : {Solution().isPowerOfThree(-1)}")