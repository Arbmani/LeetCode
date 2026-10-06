import heapq 
class Solution:
    '''
    [Medium Problem]
    
        Given an integer array nums and an integer k, return the kth largest element in the array.

        Note that it is the kth largest element in the sorted order, not the kth distinct element.

        Can you solve it without sorting?

    '''

    def findKthLargest(self, nums: list[int], k: int) -> int:
        heap = [-num for num in nums]
        heapq.heapify(heap)
        for i in range(k - 1):
            heapq.heappop(heap)

        return -heapq.heappop(heap)

if __name__ == "__main__":
    print(f"Want : {5}, Was : {Solution().findKthLargest(nums = [3,2,1,5,6,4], k = 2)}")

    print(f"Want : {4}, Was : {Solution().findKthLargest(nums = [3,2,3,1,2,4,5,5,6], k = 4)}")