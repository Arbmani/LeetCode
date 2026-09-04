class Solution:
    '''
        Given an integer "n", count the total number of digit "1"
        appearing in all non-negative integers less than or equal to "n".

        13 -> 1 + ->
        12 -> 1 + ->
        11 -> 1 + 1 -> 
        10 -> 1 + -> 
        9  -> 0 + -> 
        8  -> 0 + -> 
        .. 
        2  -> 0 + ->
        1  -> 1 

        = 1 + 1 + 1 + 1 + 1 + 1 = 6

        from 0 - 9      it appears once
        from 19 - 10    it appears 11 times (2 times in 11)
        from 99 - 20    it appears 8  times 

        from 100 - 0     it appears 21 times   

        from 
        
        30 = 21 + 19 - 10 + 1 = 12 


    '''

    def countDigitOne(self, n:int) -> int:
        count   = 0
        factor  = 1

        while factor <= n:
            higher  =  n // (factor * 10)
            current = (n // factor) % 10
            lower   =  n % factor

            if current == 0:
                count += higher * factor
            elif current == 1:
                count += higher * factor + lower + 1
            else:
                count += (higher + 1) * factor
            factor *= 10

        return count

if __name__ == "__main__":
    print(Solution().countDigitOne(n=100))
    print(Solution().countDigitOne(n=10))
    print(Solution().countDigitOne(n=30))
    print(Solution().countDigitOne(n=13))
    print(Solution().countDigitOne(n=0))