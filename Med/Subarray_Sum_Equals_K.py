class Solution:
    '''
    [Medium Problem]

        Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

        A subarray is a contiguous non-empty sequence of elements within an array.
    
    '''


    def subarraySum(self, nums: list[int], k: int) -> int:
        ans = curSum = 0
        prefix_Sums = {0: 1}
        for num in nums:
            curSum += num 
            diff    = curSum - k 
            ans += prefix_Sums.get(diff, 0)
            prefix_Sums[curSum] = 1 + prefix_Sums.get(curSum, 0)

        return ans


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().subarraySum(nums = [1,1,1], k = 2)}")

    print(f"Want : {2}, Was : {Solution().subarraySum(nums = [1,2,3], k = 3)}")