class Solution:
    '''
    [Medium Problem]

        A peak element is an element that is strictly greater than its neighbors.

        Given a 0-indexed integer array nums, find a peak element, and return its index. 
        If the array contains multiple peaks, return the index to any of the peaks.

        You may imagine that nums[-1] = nums[n] = -∞. 
        In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

        You must write an algorithm that runs in O(log n) time.

    '''


    def findPeakElement(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2

            if mid > 0 and nums[mid] < nums[mid - 1]:
                right = mid - 1
            elif mid < len(nums) -1 and nums[mid] < nums[mid + 1]:
                left = mid + 1
            else: return mid


        return -1


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().findPeakElement(nums = [1,2,3,1])}")
    print(f"Want : {5}, Was : {Solution().findPeakElement(nums = [1,2,1,3,5,6,4])}")