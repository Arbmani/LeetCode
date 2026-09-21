class Solution:
    '''
    [Medium Problem]

        You are given an integer array nums. In one operation, you can sleect a subarray
        and replace it with a single element equal to its maximum value.

        Return the maximum possible size of the array after performing zero or more operations
        such that the resulting array is non-decreasing
    
    
    '''
    def maximumPossibleSize(self, nums: list[int]) -> int:
        ans = 0 
        min_val = -1
        for num in nums:
            if num >= min_val:
                min_val = num
                ans     += 1
        return ans    


    def maximumPossibleSize_slow(self, nums: list[int]) -> int:
        ans = len_nums = len(nums)
        min_val = nums[0]
        for index in range(len_nums):
            if nums[index] >= min_val:
                min_val = nums[index]
            else: 
                ans -= 1
        return ans


if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().maximumPossibleSize(nums = [1,2,1,1,2])}")
    print(f"Want : {3}, Was : {Solution().maximumPossibleSize(nums = [4,2,5,3,5])}")
    print(f"Want : {3}, Was : {Solution().maximumPossibleSize(nums = [1,2,3])}")