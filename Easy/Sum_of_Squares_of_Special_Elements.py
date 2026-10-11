class Solution:
    '''
    [Easy Problem]

        You are given a 1-indexed integer array nums of length n.

        An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.

        Return the sum of the squares of all special elements of nums.
    
    '''


    def sumOfSquares(self, nums: list[int]) -> int:
        ans, n = 0, len(nums)
        for index, num in enumerate(nums):
            if 0 == n % (index + 1): ans += num * num
        return ans 

if __name__ == "__main__":
    print(f"Want : {21}, Was : {Solution().sumOfSquares(nums = [1,2,3,4])}")
    print(f"Want : {63}, Was : {Solution().sumOfSquares(nums = [2,7,1,19,18,3])}")