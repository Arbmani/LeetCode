class Solution:
    '''
    [Medium Problem]

        You are given an integer array nums and an integer x. In one operation, you can either remove 
        the leftmost or the rightmost element from the array nums and subtract its value from x.
        Note that this modifies the array for future operaitons.

        Return the minimum number of operations to reduce x to exactly 0 if its possible, otherwise, return -1. 
    
    
    '''

    def minOperations(self, nums: list[int], x: int) -> int:
        target = sum(nums) - x 
        if target < 0: return -1 
        if target == 0: return len(nums)

        current_sum, left, max_len = 0, 0, -1
        for right, num in enumerate(nums):
            current_sum += num 
            while left <= right and current_sum > target:
                current_sum -= nums[left]
                left        += 1
            if current_sum == target:
                max_len = max(max_len, right - left + 1)
        return -1 if max_len == -1 else len(nums) - max_len



    def minOperations_shit(self, nums: list[int], x: int) -> int:
        len_nums = len(nums)
        left, right = [0] * (len_nums), [0] * (len_nums)
        left[0], right[0] = nums[0], nums[-1]
        for left_index in range(1, len_nums):
            left[left_index]             = left[left_index - 1] + nums[left_index]
            right_index                  = len_nums - 1 - left_index
            right[left_index]            = right[left_index - 1] + nums[right_index] 

        cache = {}
        def dfs(left_node, right_node, cum_sum):
            if cum_sum == x: return (left_node + right_node)
            if cum_sum > x or left_node + right_node >= len_nums: return float("inf")

            if (left_node, right_node) in cache: return cache[(left_node,right_node)]
            cache[(left_node,right_node)] = min(
                dfs(left_node + 1, right_node, cum_sum + nums[left_node]) if left_node + 1 < len_nums else float("inf"),
                dfs(left_node, right_node + 1, cum_sum + nums[-1 -right_node]) if right_node + 1 < len_nums else float("inf"))
            return cache[(left_node,right_node)]



        res = dfs(0, 0, 0)
        return -1 if res == float("inf") else res


if __name__ == "__main__":
    print(f"Want :  {2}, Was : {Solution().minOperations(nums = [1,1,4,2,3], x = 5)}")

    print(f"Want : {-1}, Was : {Solution().minOperations(nums = [5,6,7,8,9], x = 4)}")

    print(f"Want :  {5}, Was : {Solution().minOperations(nums = [3,2,20,1,1,3], x = 10)}")