import heapq
class Solution:
    '''
    [Medium Problem]

        You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

        Define a pair (u, v) which consists of one element from the first array and one element from the second array.

        Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

    '''

    def kSmallestPairs(self, nums1: list[int], nums2: list[int], k: int) -> list[list[int]]:
        heap, ans = [], []
        if not nums1 and not nums2 or k == 0: return ans 
        for i in range(min(k, len(nums1))):
            heapq.heappush(heap, (nums1[i] + nums2[0], i, 0))
        while heap and (len(ans) < k):
            _, i, j = heapq.heappop(heap)
            ans.append(([nums1[i], nums2[j]]))
            if j + 1 < len(nums2):
                heapq.heappush(heap, (nums1[i] + nums2[j + 1], i, j + 1))
        return ans


if __name__ == "__main__":
    print(f"Want : {[[1,2],[1,4],[1,6]]}, Was : {Solution().kSmallestPairs(nums1 = [1,7,11], nums2 = [2,4,6], k = 3)}")

    print(f"Want : {[[1,1],[1,1]]}, Was : {Solution().kSmallestPairs(nums1 = [1,1,2], nums2 = [1,2,3], k = 2)}")