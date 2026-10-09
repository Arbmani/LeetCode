class Solution:
    '''
    [Medium Problem]
    
    You are given an integer n and a string s of length n consisting of digits.

    The dial contains the digits 0 through 9 in order and is circular, 
    so 0 and 9 are adjacent. The pointer initially points to 0.

    To dial each digit of s in order, rotate the pointer until it points to that digit. 
    Each rotation moves the pointer to an adjacent digit, 
    and you may rotate in either direction. 
    Dialing a digit that the pointer already points to requires no rotations.

    Before dialing, you may perform the following operation at most once:

    -   Choose an index k such that 0 <= k < n and reverse the suffix s[k..n - 1].

    Return the minimum total number of rotations needed to dial the string after 
    optimally choosing whether to perform the operation and which suffix to reverse.

    '''
    def dist(self, start: int, end: int) -> int:
        diff = abs(start - end)
        return min(diff, 10 - diff)

    def getRotations(self, s: str) -> int:
        start = ans = 0
        for char in s:
            end     = int(char)
            ans     += self.dist(start, end)
            start   = end
        return ans

    # [1, 2, 3, 4, 5]

    # [1, 2, 3, 5, 4]
    # [1, 2, 5, 4, 3]
    # [1, 5, 4, 3, 2]
    # [5, 4, 3, 2, 1]

    # 9 -> 1 vs 1 -> 9 


    def minRotations(self, n: int, s: str) -> int:
        ans = original = self.getRotations(s)
        start, last    = 0, int(s[-1])

        for k in range(n):
            cur = int(s[k])
            candidate   = (
                original
                - self.dist(start, cur)
                + self.dist(start, last))
            ans         = min(ans, candidate)
            start       = cur 
        return ans  
        


if __name__ == "__main__":
    print(f"Want : {9}, Was : {Solution().minRotations(n = 4, s = "1502")}")
    print(f"Want : {12}, Was : {Solution().minRotations(n = 4, s = "2916")}")
    print(f"Want : {6}, Was : {Solution().minRotations(n = 4, s = "4219")}")