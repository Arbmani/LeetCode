class Solution:
    '''
    [Medium Problem]

        You are given an integer array nums.

        You may delete at most one element from nums, 
        then choose a subarray of the resulting array.

        Return the maximum possible alternating sum of the chosen subarray.

        The alternating sum of an array is the sum of its elements at even 
        indices minus the sum of its elements at odd indices. 
        The chosen subarray is reindexed starting from 0 
        before calculating its alternating sum.
    
    '''

    def maxAlternatingSum(self, nums: list[int]) -> int:
        positive_sum = negative_sum = deleted_positive_sum = deleted_negative_sum = maximum_sum = float("-inf")
        for num in nums:
            prev_positive = positive_sum
            prev_negative = negative_sum
            prev_deleted_positive = deleted_positive_sum
            prev_deleted_negative = deleted_negative_sum

            positive_sum = max(num, prev_negative + num)
            negative_sum = prev_positive - num

            deleted_positive_sum = max(prev_positive, prev_deleted_negative + num)

            deleted_negative_sum = max(prev_negative, prev_deleted_positive - num)

            maximum_sum = max(
                maximum_sum,
                positive_sum,
                negative_sum,
                deleted_positive_sum,
                deleted_negative_sum
            )

        return maximum_sum

if __name__ == "__main__":
    print(f"Want : {124}, Was : {Solution().maxAlternatingSum(nums = [36,86,-38])}")

    print(f"Want : {-72}, Was : {Solution().maxAlternatingSum(nums = [-72])}")

    print(f"Want : {11}, Was : {Solution().maxAlternatingSum(nums = [5,-5,1])}")
    print(f"Want : {110}, Was : {Solution().maxAlternatingSum(nums = [10,-5,-100])}")
    print(f"Want : {7}, Was : {Solution().maxAlternatingSum(nums = [4,7])}")