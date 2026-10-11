class Solution:
    '''
    [Medium Problem]
        
        Given an integer array nums where every element appears three times except for one, 
        which appears exactly once. Find the single element and return it.

        You must implement a solution with a linear runtime complexity and use only constant extra space.
    
    '''

    def singleNumber(self, nums: list[int]) -> int:
        ones = 0
        twos = 0
        for num in nums:
            ones = (ones ^num) & ~twos 
            twos = (twos ^num) & ~ones 
        return ones 




if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().singleNumber(nums = [2,2,3,2])}")
    print(f"Want : {99}, Was : {Solution().singleNumber(nums = [0,1,0,1,0,1,99])}")



