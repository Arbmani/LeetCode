from functools import cmp_to_key


class Solution:
    '''
    [Medium Problem]

        Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

        Since the result may be very large, so you need to return a string instead of an integer

    '''

    def largestNumber(self, nums: list[int]) -> str:
        for index, num in enumerate(nums):
            nums[index] = str(num)
        def compare(num_1, num_2):
            if num_1 + num_2 > num_2 + num_1: 
                return -1
            return 1
        nums = sorted(nums, key=cmp_to_key(compare))



if __name__ == "__main__":
    print(f"Want : {"210"}, Was : {Solution().largestNumber(nums = [10,2])}")
    print(f"Want : {"9534330"}, Was : {Solution().largestNumber(nums = [3,30,34,5,9])}")