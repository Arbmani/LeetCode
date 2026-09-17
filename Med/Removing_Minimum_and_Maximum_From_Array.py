class Solution:
    '''
    [Medium Problem]

        You are given a 0-indexed array of distinct integers "nums".

        There is an element in nums that has the lowest value and an element that has the highest value. We call them
        The minimum and maximum respectively. Your goal is to remove both these elements from the array.

        A deletion is defined as either removing an element from the fron of the array or removing an element
        from the back of the array.

        Return the minimum number of deletions it would take to remove 
        both the minimum and maximum element from the array. 

    '''


    def minimumDeletions(self, nums: list[int]) -> int:
        len_nums = len(nums)
        min_val, min_index, max_val, max_index = nums[0], 0, nums[0], 0
        for index, num in enumerate(nums):
            if min_val > num:
                min_val, min_index = num, index 
            elif max_val < num:
                max_val, max_index = num, index 

        remove_left_index   = max(min_index, max_index)
        remove_right_index  = min(min_index, max_index)

        left_deletions      = remove_left_index + 1
        right_deletions     = len_nums - remove_right_index
        both_side_deletions = (len_nums - remove_left_index) + (remove_right_index + 1)
         
        return min(left_deletions, right_deletions, both_side_deletions)


if __name__ == "__main__":
    print(f"Want : {5}, Was : {Solution().minimumDeletions(nums = [2,10,7,5,4,1,8,6])}")

    print(f"Want : {3}, Was : {Solution().minimumDeletions(nums = [0,-4,19,1,8,-2,-3,5])}")

    print(f"Want : {1}, Was : {Solution().minimumDeletions(nums = [101])}")