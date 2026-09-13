from math import gcd 
class Solution:
    '''
    [Medium Problem]

        You are given an integer array "nums".

        You may remove at most one element from "nums". Let "arr" be the array of remaining 
        elements in their original order, and let "m" be its length.

        A split position "i" of "arr" is valid if:

        -   0 <= i < m - 1, and

            -   gcd(arr[0..i]) == gcd(arr[i+1..m-1]).
        
        An array of length 1 has no valid split positions.

        The score of "arr" is the number of valid split positions in it.

        Return the maximum possible score of "arr".

        Here gcd(a) denotes the greatest common divisor of all elements in the array "a"
    '''

    def maxValidSplits(self, nums: list[int]) -> int:
        def score(arr: list[int]) -> int:
            n = len(arr)
            if n < 2: return 0
            prefix, suffix  = [0] * n, [0] * n
            prefix[0]       = arr[0]
            for i in range(1, n):
                prefix[i] = gcd(prefix[i - 1], arr[i])
            suffix[n - 1] = arr[n - 1]
            for i in range(n - 2, -1, -1):
                suffix[i] = gcd(suffix[i + 1], arr[i])
            result = 0
            for i in range(n - 1):
                if prefix[i] == suffix[i + 1]:
                    result += 1
            return result
        answer = score(nums)
        for remove in range(len(nums)):
            arr     = nums[:remove] + nums[remove + 1:]
            answer  = max(answer, score(arr))
        return answer


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().maxValidSplits(nums = [10,30,15,10])}")

    print(f"Want : {1}, Was : {Solution().maxValidSplits(nums = [2,10,14])}")

    print(f"Want : {0}, Was : {Solution().maxValidSplits(nums = [2,4])}")


