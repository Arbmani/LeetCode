from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        starting_length = len(nums)
        nums = sorted(set(nums))
        result = starting_length
        right = 0
        for left in range(len(nums)):
            while right < len(nums) and nums[right] < nums[left] + starting_length:
                right   += 1

            window      = right - left 
            result      = min(result, starting_length - window)
        return result


    



if __name__ == "__main__":
    print(Solution().minOperations(nums = [2,2,2]))
