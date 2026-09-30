class Solution:
    '''
    [Medium Problem]

        Given an integer array nums and an integer k, return True if nums has a good subarray or false otherwise.

        A good subarray is a subarray where:

        -   Its length is at least two, and

        -   The sum of the elements of the subarray is a multiple of k.

        Note that:

        -   A subarray is a contiguous part of the array.

        -   An integer "x" is a multiple of k if there exists an integer "n"
            such that x = n * k. 0 is always a multiple of k. 
    
    
    
    '''

    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        remainders = {0: -1}
        total     =  0
        for index, num in enumerate(nums):
            total += num 
            remainder = total % k 
            if remainder not in remainders:
                remainders[remainder] = index
            elif index - remainders[remainder] > 1:
                return True
        return False 


if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().checkSubarraySum(nums = [23,2,4,6,7], k = 6)}")

    print(f"Want : {True}, Was : {Solution().checkSubarraySum(nums = [23,2,6,4,7], k = 6)}")

    print(f"Want : {False}, Was : {Solution().checkSubarraySum(nums = [23,2,6,4,7], k = 13)}")