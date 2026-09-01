class Solution:
    '''
        Given an integer "num", repeatedly add all its digits
        until the result has only one digit, and return it.
    
    '''

    def addDigits(self, num: int) -> int:
        while num >= 10:
            accumulator = 0
            while num > 0:
                accumulator += num % 10
                num         =  num // 10
            num = accumulator
        return num

if __name__ == "__main__":
    print(Solution().addDigits(num=38))
    print(Solution().addDigits(num=0))