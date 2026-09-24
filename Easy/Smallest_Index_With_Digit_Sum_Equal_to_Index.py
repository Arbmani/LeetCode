class Solution:
    '''
    [Easy Problem]

        You are given an integer array "num". 

        Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

        If no such index exists return -1

       
    '''

    def smallestIndex(self, nums: list[int]) -> int:
        for index, num in enumerate(nums):
            target = 0
            while num > 0:
                target += num % 10    
                num    //= 10
            if target == index:
                return index 

        return -1



if __name__ == "__main__":
    print(f"Want :  {2}, Was : {Solution().smallestIndex( nums = [1,3,2])}")
    print(f"Want :  {1}, Was : {Solution().smallestIndex(nums = [1,10,11])}")
    print(f"Want : {-1}, Was : {Solution().smallestIndex(nums = [1,2,3])}")