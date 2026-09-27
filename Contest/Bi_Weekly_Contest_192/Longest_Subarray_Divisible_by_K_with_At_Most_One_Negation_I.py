class Solution:
    '''
    [Medium Problem]

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
        for i, x in enumerate(nums):
            prefix[i + 1] = (prefix[i] + x) % k 
        ans = 0
        first = {}
        for remainder in range(n + 1):
            new_remainder = prefix[remainder]
            if new_remainder in first:
                ans = max(ans, remainder - first[new_remainder])
            else:
                first[new_remainder] = remainder

        for remainder in range(n):
            first = {}
            for t in range(remainder + 1):
                rem = prefix[t]
                if rem not in first:
                    first[rem] = t 
                target = (prefix[remainder + 1] - 2 * nums[t]) % k 
                if target in first:
                    l = first[target]
                    ans = max(ans, remainder - l + 1)


        return ans 


if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().longestSubarray(nums = [4,1,2], k = 3)}")
    print(f"Want : {2}, Was : {Solution().longestSubarray(nums = [5,3,4], k = 7)}")
    print(f"Want : {2}, Was : {Solution().longestSubarray(nums = [2,2,5], k = 6)}")