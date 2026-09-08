class Solution:
    '''
    [Medium Problem]

        You are given an integer array "nums" of even length "n"

        A cyclic rotation of "nums" is obtained by choosing a "prefix" of "nums"
        whose length is between "0" and "n-1" (inclusive), and moving it to the
        end of the array while preserving the order of all elements.

        A cyclic rotation is good if the sum of its first "n / 2" elements is
        strictly greater than the sum of its last "n / 2" elements. 

        Return the number of cyclic rotations of "nums" that are good.
    '''
    # nums[1] -> 1, 2, 3 = 6 
    # nums[2] -> 2, 3, 4 = 9 
    # nums[3] -> 3, 4, 5 = 12 
    # nums[4] -> 4, 5, 6 = 15 
    # nums[5] -> 5, 6, 1 = 12 
    # nums[6] -> 6, 1, 2 = 9

    def countGoodRotations(self, nums: list[int]) -> int:
        len_nums = len(nums)
        len_half = len_nums // 2
        total_sum, left_sum, good  = sum(nums), sum(nums[:len_half]), 0
        for start in range(len_nums):
            if 2 * left_sum > total_sum:
                good += 1
            left_sum = left_sum + (nums[(start + len_half) % len_nums] - nums[start])

        return good


if __name__ == "__main__":
    
    print(f"Want : {3}, Was : {Solution().countGoodRotations(nums = [1,2,3,4,5,6])}")

    print(f"Want : {0}, Was : {Solution().countGoodRotations(nums = [1,2,1,2])}")