class Solution:
    '''
        Given an integer "num", repeatedly add all its digits
        until the result has only one digit, and return it.
    
    '''

    def addDigits(self, num: int) -> int:
        '''
            Intuition

            This problem asks us to repeatedly sum digits of a number until only a 
            single digits remains. The elegant mathematical insight is that this "digital root"
            follows a pattern: it equals (num - 1) % 9 + 1 for positive numbers.

            10 % 9 = 1 
            13 % 9 = 4 

            Approach

            We'll use a mathematical pattern recognition strategy:

            1.  Zero case: if num is 0 digital root is 0.

            2.  Multiples of 9: if num % 9 equals 0 (and num != 0), digital root is 9.

            3.  General case: For all other numbers, digital root is num % 9.

            4.  Mathematical property: This works because repeatedly summing digits
                is equivalent to finding the remainder when divided by 9.

            
        
        '''
        if num == 0:
            return 0
        if num % 9 == 0:
            return 9
        return num % 9 

    def addDigits2(self, num: int) -> int:
        if num == 0:
            return 0
        return 1 + (num - 1) % 9

if __name__ == "__main__":
    print(Solution().addDigits(num=38))
    print(Solution().addDigits(num=0))