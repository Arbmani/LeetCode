class Solution:
    '''
    Given "n" points on a 1-D plane, where the "i"th point (from 0 to n-1) is at x = i, find 
    the number of ways we can draw exactly k non-overlapping line segments such that each
    segment covers two or more points. The endpoint of each segment must have integral
    coordinates. The k line segments do not have to cover all n points, and they are 
    allowed to share endpoints. 

    Return the number of ways we can draw k non-overlapping line segments.
    Since this number can be huge, return it modulo 10^9 + 7
    
    '''


    def numberOfSets(self, n: int, k: int) -> int:
        modulo = 10**9 + 7
        cache  = [[0] * (k + 1) for _ in range(n)]
        for i in range(n):
            cache[i][0] = 1
        for i in range(1, k + 1):
            total = 0
            for j in range(1, n):
                total       = (total + cache[j - 1][i - 1]) % modulo
                cache[j][i] = (cache[j - 1][i] + total)     % modulo
        return cache[n - 1][k]


if __name__ == "__main__":
    print(f"Want : {5}, Was : {Solution().numberOfSets(n = 4, k = 2)}")

    print(f"Want : {3}, Was : {Solution().numberOfSets(n = 3, k = 1)}")

    print(f"Want : {796297179}, Was : {Solution().numberOfSets(n = 30, k = 7)}")