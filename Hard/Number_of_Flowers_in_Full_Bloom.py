import heapq
class Solution:
    '''
    [Hard Problem]


        You are given a 0-indexed 2D integer array flowers, where floers[i] = [start_i, end_i] means the 
        "i"th flower will be in full bloom start_i to end_i (inclusive). You are also given a 0-indexed 
        interger array people of size n, where people[i] is the time that the ith person will arrive
        to see the flowers.

        Return an integer array answer of size, n" where answer[i] is the numebr of flowers that
        are in full bloom when the ith person arrives. 
    
    
    '''
    def fullBloomFlowers(self, flowers: list[list[int]], people: list[int]) -> list[int]:
        people  = [(p, i) for i, p in enumerate(people)]
        res     = [0] * len(people)
        flowers.sort()
        end = []
        j = 0
        for p, i in sorted(people):
            while j < len(flowers) and flowers[j][0] <= p:
                heapq.heappush(end, flowers[j][1])
                j += 1
            while end and end[0] < p:
                heapq.heappop(end)
            res[i] = len(end)
        return res 

    def fullBloomFlowers_slow(self, flowers: list[list[int]], people: list[int]) -> list[int]:
        people = [(p, i) for i, p in enumerate(people)]
        res    = [0] * len(people)
        countr = 0
        start  = [f[0] for f in flowers]
        end    = [f[1] for f in flowers]
        heapq.heapify(start)
        heapq.heapify(end)
        for person, index in sorted(people):
            while start and start[0] <= person:
                heapq.heappop(start)
                countr += 1
            while end and end[0] < person:
                heapq.heappop(end) 
                countr -= 1
            res[index] = countr

        
        return res


if __name__ == "__main__":
    print(f"Want : {[1,2,2,2]}, Was : {Solution().fullBloomFlowers(flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11])}")

    print(f"Want : {[2,2,1]}, Was : {Solution().fullBloomFlowers(flowers = [[1,10],[3,3]], people = [3,3,2])}")