class Solution:
    '''
    [Easy Problem]

        You are given an array nums1 of "n" distinct intergers.

        You want to construct another array "nums2" of length "n" such that the elements of "nums2"
        are either all odd or all even.

        For each index "i" you must choose exactly one of the following (in any order):
        
        -   nums2[i] = nums1[i]

        -   nums2[i] = nums1[i] - nums1[j], for an index j != i

        Return True if its possible to construct such an array, otherwise return false.
    
    '''

    def uniformArray(self, nums1: list[int]) -> bool:
        return True


if __name__ == "__main__":
    print(f"Want : {True}, Was : {Solution().uniformArray(nums1 = [2,3])}")

    print(f"Want : {True}, Was : {Solution().uniformArray(nums1 = [4,6])}")