class Solution:
    '''
    [Easy Problem]

        Given two integer arrays nums1 and nums2, return an array of their 
        intersection. Each element in the result must be unique, and you may
        return the result in any order. 
    
    
    '''

    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        return list(set(nums1).intersection(nums2))


if __name__ == "__main__":
    print(f"Want : {[2]}, Was : {Solution().intersection(nums1 = [1,2,2,1], nums2 = [2,2])}")
    print(f"Want : {[9,4]}, Was : {Solution().intersection(nums1 = [4,9,5], nums2 = [9,4,9,8,4])}")