class Solution:
    '''
    [Hard Problem]

        You are given an integer array nums and an integer "k".

        A subarray is valid if its sum is divisible by k, or can become divisible
        by k by negating one element within that subarray.

        Negating an element means replacing its value "x" with "-x".
        
        Return the length of the longest valid subarray. If no valid subarray exists,
        return 0.

        A subarray is a contiguous, non-empty sequence of elements within an array.
    
    '''
    def longestSubarray(self, nums: list[int], k: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        positions = [[] for _ in range(k)]

        for i, x in enumerate(nums):
            prefix[i + 1] = (prefix[i] + x) % k 
            b = (2 * x) % k 
            positions[b].append(i)

        first, last = [-1]*k, [-1]*k 
        for i, remainder in enumerate(prefix):
            if first[remainder] == -1:
                first[remainder] = i
            last[remainder] = i 
        ans = 0
        for remainder in range(k):
            if first[remainder] != -1:
                ans = max(ans, last[remainder] - first[remainder])
        order = [remainder for remainder in range(k) if first[remainder] != -1]
        order.sort(key=first.__getitem__)
        for b, occurrences in enumerate(positions):
            if not occurrences: continue
            ptr = 0
            m = len(occurrences)
            for q in order:
                L = first[q]
                while ptr < m and occurrences[ptr] < L:
                    ptr += 1
                if ptr == m:
                    break
                R = last[(q + b) % k]
                if R > L and occurrences[ptr] < R:
                    ans = max(ans, R - L)

        return ans


if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().longestSubarray(nums = [4,1,2], k = 3)}")
    print(f"Want : {2}, Was : {Solution().longestSubarray(nums = [5,3,4], k = 7)}")
    print(f"Want : {2}, Was : {Solution().longestSubarray(nums = [2,2,5], k = 6)}")