from math import gcd 
class Solution:
    '''
    [Medium Problem]

        An ugly number is a positive integer that is divisble by a, b, or c.

        Given four integers n, a, b, and c, return the nth ugly number.
    
    
    '''

    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        def lcm(x, y):
            return x * y // gcd(x, y)
        ab  = lcm(a,b)
        ac  = lcm(a,c)
        bc  = lcm(b,c)
        abc = lcm(ab, c)
        def count(x):
            return((x // a) + (x // b) + (x //c) - (x // ab) - (x // ac) - (x // bc) + (x // abc))

        left = 1
        right = min(a, b, c) * n 
        while(left < right):
            mid = (left + right) // 2
            if count(mid) >= n:
                right = mid 
            else:
                left = mid + 1
        return left




if __name__ == "__main__":
    print(f"Want : {4}, Was : {Solution().nthUglyNumber(n = 3, a = 2, b = 3, c = 5)}")

    print(f"Want : {6}, Was : {Solution().nthUglyNumber(n = 4, a = 2, b = 3, c = 4)}")

    print(f"Want : {10}, Was : {Solution().nthUglyNumber(n = 5, a = 2, b = 11, c = 13)}")