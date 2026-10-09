from functools import lru_cache
from bisect import bisect_left, bisect_right
class Solution:
    '''
    [Hard Problem]

        Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, 
        a stick of length 6 is labelled as follows:

        Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

        You should perform the cuts in order, you can change the order of the cuts as you wish.

        The cost of one cut is the length of the stick to be cut, 
        the total cost is the sum of costs of all cuts.
        When you cut a stick, it will be split into two smaller sticks 
        (i.e. the sum of their lengths is the length of the stick before the cut). 
        Please refer to the first example for a better explanation.

        Return the minimum total cost of the cuts.
    
    '''

    def minCost(self, n: int, cuts: list[int]) -> int:
        cuts.sort()
        cuts = [0] + cuts + [n]

        @lru_cache(None)
        def dfs(left: int, right: int) -> int:
            start = bisect_right(cuts, left)
            end   = bisect_left(cuts, right)

            if start >= end: return 0
            cost = right - left 
            best = float("inf")

            for i in range(start, end):
                total = (cost + dfs(left, cuts[i]) + dfs(cuts[i], right))
                best = min(best, total)
            return best 
        return dfs(0, n)

        # sort cuts
        # binary search for available cuts between left boundary and right boundary
        # if only 1 cut left return 
        # run dfs
        # allways pick greedly the cut between left and right



if __name__ == "__main__":
    print(f"Want : {16}, Was : {Solution().minCost(n = 7, cuts = [1,3,4,5])}")
    print(f"Want : {22}, Was : {Solution().minCost(n = 9, cuts = [5,6,1,4,2])}")