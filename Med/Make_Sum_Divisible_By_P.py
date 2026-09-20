class Solution:
    '''
    [Medium Problem]

        Given an array of positive integers nums, remove the smallest subarray (possible empty) such that
        the sum of remaining elements is divisible by p. It is not allowed to remove the whole array.

        Return the length of the smallest subarray that you need to remove, or -1 if its impossible.

        A subarray is defined as a contiguous block of elements in the array.
    
    '''


    def minSubarray(self, nums: list[int], p: int) -> int:
        total  = sum(nums)
        target = total % p 
        if target == 0: return  0 
        if total  < p : return -1 
        prefix, prefix_index = 0, {0: -1}
        best = len(nums)
        for index, num in enumerate(nums):
            prefix = (prefix + num)    % p
            needed = (prefix - target) % p 

            if needed in prefix_index:
                best = min(best, index - prefix_index[needed])
            prefix_index[prefix] = index 

        return -1 if best == len(nums) else best


if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().minSubarray(nums = [26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3], p = 26)}")

    print(f"Want : {-1}, Was : {Solution().minSubarray(nums = [1,2,3], p = 7)}")

    print(f"Want : {1}, Was : {Solution().minSubarray(nums = [3,1,4,2], p = 6)}")
    print(f"Want : {2}, Was : {Solution().minSubarray(nums = [6,3,5,2], p = 9)}")
    print(f"Want : {0}, Was : {Solution().minSubarray(nums = [1,2,3], p = 3)}")