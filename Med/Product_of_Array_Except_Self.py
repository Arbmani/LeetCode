class Solution:
    '''
    [Medium Problem]

        Given an integer array nums, return an array "answer" such that answer[i] is equal to the product
        of all the elements of nums except nums[i].

        The product of any prefix or suffix of nums is guranteed to fit in a 32-bit integer.

        You must write an algorithm that runs in O(n) time and without using the diviosnm operation. 
    
    
    
    '''
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        len_nums = len(nums)
        ans = [1] * len_nums
        prefix = 1
        for index, num in enumerate(nums):
            ans[index] = prefix
            prefix    *= num 
        suffix = 1
        for index in range(len_nums - 1, -1, -1):
            ans[index] *= suffix
            suffix     *= nums[index] 
             

        return ans

    def productExceptSelf_slow(self, nums: list[int]) -> list[int]:
        ans = [1] * len(nums)
        prefix = 1
        for index, num in enumerate(nums):
            ans[index] = prefix
            prefix    *= num 
        suffix = 1
        for index, num in reversed(list(enumerate(nums))):
            ans[index] *= suffix
            suffix    *= num 
             

        return ans


if __name__ == "__main__":
    print(f"Want : {[24,12,8,6]}, Was : {Solution().productExceptSelf(nums = [1,2,3,4])}")

    print(f"Want : {[0,0,9,0,0]}, Was : {Solution().productExceptSelf(nums = [-1,1,0,-3,3])}")