class Solution:
    '''
    [Medium Problem]

        Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
        whose sum is greater than or equal to target. If there is not such subarray, return 0 instead. 
    
    '''
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        left = curSum = 0
        ans  = float("inf")
        for right, num in enumerate(nums):
            curSum += num 
            while curSum >= target:
                ans = min(ans, (right - left) + 1)
                curSum -= nums[left]
                left += 1
        return 0 if ans == float("inf") else ans  

 

    def minSubArrayLen_slow(self, target: int, nums: list[int]) -> int:
        left = right = 0
        len_nums = len(nums)
        currSum = 0
        ans = float("inf")
        while (left < len_nums):
            while currSum < target and right < len_nums:
                currSum += nums[right]
                right += 1
            if currSum >= target:
                ans = min(ans, (right - left))
                currSum -= nums[left]
                left += 1
            else: break

        
        return ans if ans != float("inf") else 0


if __name__ == "__main__":  
    print(f"Want : {2}, Was : {Solution().minSubArrayLen(target = 7, nums = [2,3,1,2,4,3])}")

    print(f"Want : {1}, Was : {Solution().minSubArrayLen(target = 4, nums = [1,4,4])}")

    print(f"Want : {0}, Was : {Solution().minSubArrayLen(target = 11, nums = [1,1,1,1,1,1,1,1])}")