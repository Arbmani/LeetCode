class Solution:
    '''
    [Easy Problem]


        You are given a binary array nums (0-indexed).

        We define x_i as the number whose binary representation is the subarray nums[0..i]
        from most significant bit to least significant bit.

        -   For example if nums = [1, 0, 1] then x_0 = 1, x_1 = 2, and x_2 = 5.

        Return an array of booleans answer where answer[i] is true if x_1 is divisble by 5. 

    
    '''

    def prefixesDivBy5(self, nums: list[int]) -> list[bool]:
        curr = 0
        for index, bit in enumerate(nums):
            curr = ((curr << 1) + bit) % 5
            nums[index] = curr == 0
        return nums



if __name__ == "__main__":
    print(f"Want : {[True,False,False,False,False,True]}, Was : {Solution().prefixesDivBy5(nums = [0,1,1,1,1,1])}")

    print(f"Want : {[True, False, False]}, Was : {Solution().prefixesDivBy5(nums = [0,1,1])}")

    print(f"Want : {[False, False, False]}, Was : {Solution().prefixesDivBy5(nums = [1,1,1])}")