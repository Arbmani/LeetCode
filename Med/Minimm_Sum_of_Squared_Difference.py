import heapq 
class Solution:
    '''
    [Medium Problem]


        You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

        The sum of squared difference of arrays nums1 and nums2 is defined as the sum of 
        (nums1[i] - nums2[i])**2 for each 0 <= i < n.

        You are also given two positive integers k1 and k2. 
        You can modify any of the elements of nums1 by +1 or -1 at most k1 times. 
        Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

        Return the minimum sum of squared difference after modifying array nums1 at most k1 times and 
        modifying array nums2 at most k2 times.

        Note: You are allowed to modify the array elements to become negative integers.
    
    
    
    '''

    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        n = len(nums1)      # 1 <= n <= 10**5, nums[index] <= 10**5, 0 <= k1, k2 <= 10**9
        k1    += k2 
        if k1 == 0         : return sum((nums1[index] - nums2[index])**2 for index in range(n))
        diffs  = sorted(abs(num1 - num2) for num1, num2 in zip(nums1, nums2))
        if k1 >= sum(diffs): return 0
        n = len(nums1)
        for index in range(n - 1, -1, -1):
            count       = n - index 
            previous    = diffs[index - 1] if index else 0
            cost        = (diffs[index] - previous) * count 
            if k1 >= cost:
                k1 -= cost 
            else:
                q, r    = divmod(k1, count)
                level   = diffs[index] - q
                diffs[index:] = [level] * count
                for j in range(n - r, n):
                    diffs[j] -= 1 
                break
        return sum(x * x for x in diffs)


if __name__ == "__main__":  
    print(f"Want : {0}, Was : {Solution().minSumSquareDiff(nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 10, k2 = 5)}")

    #This test case is wrong print(f"Want : {579}, Was : {Solution().minSumSquareDiff(nums1 = [1,2,3,40], nums2 = [2,10,20,19], k1 = 10, k2 = 0)}")
    print(f"Want : {579}, Was : {Solution().minSumSquareDiff(nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0)}")
    print(f"Want : {43}, Was : {Solution().minSumSquareDiff(nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1)}")