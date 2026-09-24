class Solution:
    '''
    [Easy Problem]

        Given a positive integer num, return True if num is a perfect square or False otherwise.

        A perfect square is an integer that is the square of an integer. In other words,
        it is the product of some integer with itself.

        You most not use any built-in library function, such as sqrt.
    
    '''

    def isPerfectSquare(self, num: int) -> bool:
        if num < 2: return True
        left, right = 2, num // 2  
        while(left <= right):
            mid = (left + right) // 2
            value = mid * mid
            if value == num: return True 
            elif value > num: right = mid - 1
            else: left = mid + 1

        return False


if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().isPerfectSquare(16)}")
    print(f"Want : {False}, Was : {Solution().isPerfectSquare(14)}")