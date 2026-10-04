import heapq
class Solution:
    '''
    [Hard Problem]

        You are given a 2D integer array, intervals, where intervals[i] = [left_i, right_i] describes the "i"th
        interval strating at left_i and ending at right_i (inclusive). The size of an interval is defined as
        the number of intergers it contains, or more formally right_i - left_i + 1.

        You are also given an integer array queries. The answer to the "j"th query is the size of the smallest
        interval "i" such that left_i <= queries[j] <= right_i. If no such interval exists,
        the answer is -1.

        Return an array containing the answers to the queries. 
    
    
    
    '''

    def minInterval(self, intervals: list[list[int]], queries: list[int]) -> list[int]:
        intervals.sort()
        minheap = []
        res, index = {}, 0
        for query in sorted(queries):
            while index < len(intervals) and intervals[index][0] <= query:
                left, right = intervals[index]
                heapq.heappush(minheap, (right - left + 1, right))
                index += 1
            while minheap and minheap[0][1] < query:
                heapq.heappop(minheap)
            res[query] = minheap[0][0] if minheap else -1
        return [res[query] for query in queries]

if __name__ == "__main__":
    print(f"Want : {[3,3,1,4]}, Was : {Solution().minInterval(intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5])}")

    print(f"Want : {[2,-1,4,6]}, Was : {Solution().minInterval(intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22])}")