class Solution:
    '''
    [Easy Problem]

        You are given a 2D integer array intervals of n elements, where intervals[i] = [start_i, end_i] 
        represents the closed interval from start_i to end_i.

        Return the number of pairs of indices (i, j) such that 0 <= i < j < n
        and intervals[i] and intervals[j] intersect.

        Two intervals intersect if they have at least one point in common,
        including when they only share an endpoint. 
    
    '''

    def countIntersectingIntervals(self, intervals: list[list[int]]) -> int:
        len_intervals = len(intervals)
        starts = sorted(start for start, end in intervals) 
        ends   = sorted(end   for start, end in intervals)
        no_intersect = before = 0
        for start in starts:
            while (before < len_intervals) and (ends[before] < start):
                before += 1
            no_intersect += before 
        total_pairs = (len_intervals * (len_intervals - 1) // 2) - no_intersect
        return total_pairs


if __name__ == "__main__":
    print(f"Want : {2}, Was : {Solution().countIntersectingIntervals(intervals = [[1,2],[2,3],[3,4]])}")

    print(f"Want : {3}, Was : {Solution().countIntersectingIntervals(intervals = [[1,5],[2,4],[3,6]])}")

    print(f"Want : {0}, Was : {Solution().countIntersectingIntervals(intervals = [[1,2],[3,4],[5,6]])}")