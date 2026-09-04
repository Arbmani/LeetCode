import heapq
class Solution:
    '''
        You are given an integer array "nums" of length "n" and an integer "k".

        For each index "i", define its instability score as "max(nums[0...i]) - min(nums[i..n - 1]).

        In other words:

        -   max(nums[0..i]) is the largest value among the elements from index 0 to index i.

        -   min(nums[i..n-1]) is the smallest value among the elements from index "i" to index "n - 1".

        An index "i" is called stable if its instability score is less than or equal to "k".

        Return the smallest stable index. If no such index exists, return - 1.
    '''

    def firstStableIndex(self, nums: list[int], k: int) -> int:
        len_nums, max_val           = len(nums)     , nums[0]
        min_array, min_array[-1]    = [0] * len_nums, nums[-1] 
        for index in range(len_nums - 2, -1, -1):
            min_array[index] = min(nums[index], min_array[index + 1])

        for index in range(len_nums):
            max_val = max(max_val, nums[index])
            if max_val - min_array[index] <= k:
                return index
        return -1


if __name__ == "__main__":
    print(f"Expected answer : {3}, Mine was : {Solution().firstStableIndex(nums=[5,0,1,4], k = 3)}")

    print(f"Expected answer : {-1}, Mine was : {Solution().firstStableIndex(nums = [3,2,1], k = 1)}")

    print(f"Expected answer : {0}, Mine was : {Solution().firstStableIndex(nums = [0], k = 0)}")