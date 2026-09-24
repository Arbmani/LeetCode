class Solution:
    '''
    [Easy Problem]

        Given two integer arrays nums1 and nums2, return an array of their 
        intersection. Each element in the result must appear as many times
        as it shows in both arrays and you may return the result in any order.
    
    
    '''
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
        freak = {}
        for num in nums1:
            freak[num] = freak.get(num, 0) + 1
        res = []
        for num in nums2:
            if freak.get(num, 0) > 0:
                res.append(num)
                freak[num] -= 1
        return res



if __name__ == "__main__":
    print(f"Want : {[4,9]}, Was : {Solution().intersect(nums1 = [4,9,5], nums2 = [9,4,9,8,4])}")
    print(f"Want : {[2,2]}, Was : {Solution().intersect(nums1 = [1,2,2,1], nums2 = [2,2])}")