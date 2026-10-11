class Solution:
    '''
    [Medium Problem]

        Given an integer array nums, find a subarray that has the largest product, and return the product.

        The test cases are generated so that the answer will fit in a 32-bit integer.

        Note that the product of an array with a single element is the value of that element.
    
    '''
    def maxProduct(self, nums: list[int]) -> int:
        max_cur = min_cur = result = nums[0]
        for num in nums[1:]:
            if num < 0:
                max_cur, min_cur = min_cur, max_cur
            max_cur = max(num, num*max_cur)
            min_cur = min(num, num*min_cur)
            result = max(result, max_cur)
        return result



if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().maxProduct(nums = [-3,-1,-1])}")

    print(f"Want : {-2}, Was : {Solution().maxProduct(nums = [-2])}")

    print(f"Want : {6}, Was : {Solution().maxProduct(nums = [2,3,-2,4])}")
    print(f"Want : {0}, Was : {Solution().maxProduct(nums = [-2,0,-1])}")


        