import heapq 
class Solution:
    '''
    [Medium Problem]

        Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
    
    '''
    # C 
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        frequency_counter = {}
        for num in nums: frequency_counter[num] = frequency_counter.get(num, 0) + 1
        return heapq.nlargest(k, frequency_counter, key=frequency_counter.get)


    #   Bucket Sort
    def topKFrequent_Bucket(self, nums: list[int], k: int) -> list[int]:
        frequency_counter = {}
        for num in nums: frequency_counter[num] = frequency_counter.get(num, 0) + 1

        buckets = [[] for _ in range(len(nums) + 1)]
        for num, freq in frequency_counter.items():
            buckets[freq].append(num)
        res = []
        for freq in range(len(nums), 0, -1):
            for num in buckets[freq]:
                res.append(num)
                if len(res) == k: return res 
        return res


    def topKFrequent_slow(self, nums: list[int], k: int) -> list[int]:
        frequency_counter = {}
        for num in nums:
            frequency_counter[num] = frequency_counter.get(num, 0) + 1
        heap = []
        for num, freq in frequency_counter.items():
            heapq.heappush(heap, (-freq, num))
        ans = [0] * k
        for index in range(k):
            ans[index] = heapq.heappop(heap)[1]
        return ans 


if __name__ == "__main__":
    print(f"Want : {[1,2]}, Was : {Solution().topKFrequent(nums = [1,1,1,2,2,3], k = 2)}")

    print(f"Want : {[1]}, Was : {Solution().topKFrequent(nums = [1], k = 1)}")

    print(f"Want : {[1,2]}, Was : {Solution().topKFrequent(nums = [1,2,1,2,1,2,3,1,3,2], k = 2)}")