class Solution:
    '''
    [Medium Problem]

        You are given an array nums1 of n distinct integers

        You want to construct another array nums2 of length n such that the elements in 
        nums2 are either all odd or all even.

        For each index "i", you must choose exactly one of the following (in any order):

        -   nums2[i] == nums1[i]

        -   nums2[i] == nums1[i] - nums1[j], for an index j != i, such that 
            nums1[i] - nums1[i] > 0
        
        Return true if its possible to construct such an array, otherwise return false.

    '''
    def uniformArray(self, nums1: list[int]) -> bool:   # Not faster just less code
        min_val, has_odd = float("inf"), False
        for num in nums1:
            min_val = min(min_val, num)
            has_odd |= num % 2 == 1
        return not(has_odd and min_val % 2 == 0)

    def uniformArray_fat(self, nums1: list[int]) -> bool:
        min_val = float("inf")
        is_odd  = False
        for num in nums1:
            if num % 2 == 1:
                is_odd = True
            min_val = min(min_val, num)

        if is_odd and min_val % 2 == 0:
            return False

        return True 

if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().uniformArray(nums1 = [1,4,7])}")

    print(f"Want : {False}, Was : {Solution().uniformArray(nums1 = [2,3])}")

    print(f"Want : {True}, Was : {Solution().uniformArray(nums1 = [4,6])}")