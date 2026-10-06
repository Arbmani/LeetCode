import heapq
class Solution:
    '''
    [Easy Problem]

        You are given an array of integers stones where stones[i] is the weight of the ith stone.

        We are playing a game with the stones. 
        On each turn, we choose the heaviest two stones and smash them together. 
        Suppose the heaviest two stones have weights x and y with x <= y. 
        The result of this smash is:
        
        -   If x == y, both stones are destroyed, and
        
        -   If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
        
        At the end of the game, there is at most one stone left.

        Return the weight of the last remaining stone. If there are no stones left, return 0.

    '''
    def lastStoneWeight(self, stones: list[int]) -> int:
        heap = [-stone for stone in stones]
        heapq.heapify(heap)
        while len(heap) > 1:
            y = -heapq.heappop(heap)
            x = -heapq.heappop(heap)
            if y != x:
                heapq.heappush(heap, -(y - x))
        
        return -heap[0] if heap else 0

    def lastStoneWeight_ugly(self, stones: list[int]) -> int:
        heap = []
        for stone in stones:
            heapq.heappush(heap,-stone)
        stone_1 = 0
        while heap:
            stone_1 = -heapq.heappop(heap)
            
            stone_2 = 0
            if heap: stone_2 = -heapq.heappop(heap)
            if stone_1 and stone_2:
                if stone_1 != stone_2:
                    heapq.heappush(heap, -(stone_1 - stone_2))
                else: stone_1 = 0
        return stone_1
    
if __name__ == "__main__":
    print(f"Want : {1}, Was : {Solution().lastStoneWeight(stones = [2,7,4,1,8,1])}")

    print(f"Want : {1}, Was : {Solution().lastStoneWeight(stones = [1])}")

    print(f"Want : {2}, Was : {Solution().lastStoneWeight(stones = [1,3])}")